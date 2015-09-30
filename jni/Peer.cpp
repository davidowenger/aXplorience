#include "Common.h"

namespace NSDEVICE
{

Peer::Peer(Wrapper* const w, BluetoothDevice* vBluetoothDevice, const String& vsMac, bool vIsClient)
    : w(w), mBluetoothDevice(vBluetoothDevice), mBluetoothGatt(nullptr), mBluetoothGattCharacteristic(nullptr), mNetworkClientCallback(nullptr), mMac(vsMac), mAsClient(vIsClient)
{
    if (mAsClient) {
        mNetworkClientCallback = new NetworkClientCallback(w, this);
        LOGD(("Connecting to server : #" + mMac).c_str());
        unique_lock<mutex> vUniqueLock(w->mMutex);
        mBluetoothGatt = mBluetoothDevice->connectGatt(w->mNActivity, false, mNetworkClientCallback, BluetoothDevice::TRANSPORT_LE);
        w->mConditionStateChange.wait_for(vUniqueLock, 300000*w->mMili);
        vUniqueLock.unlock();
    }
}

Peer::~Peer()
{
    if (mBluetoothGattCharacteristic) {
        delete mBluetoothGattCharacteristic;
    }
    if (mNetworkClientCallback) {
        delete mNetworkClientCallback;
    }
    if (mBluetoothGatt) {
        delete mBluetoothGatt;
    }
    if (mBluetoothDevice) {
        delete mBluetoothDevice;
    }
}

nuint Peer::write(const String& vPacked)
{
    nuint ret = 1;

    if (mAsClient) {
        if (mBluetoothGattCharacteristic) {
            LOGD(("Sending data to server : #" + mMac).c_str());
            mBluetoothGattCharacteristic->setValue(vPacked);
            unique_lock<mutex> vUniqueLock(w->mMutex);
            ret = !mBluetoothGatt->writeCharacteristic(mBluetoothGattCharacteristic);
            w->mConditionCharacteristicWrite.wait_for(vUniqueLock, 20000*w->mMili);
            vUniqueLock.unlock();

            if (ret) {
                LOGD(("Write failed because write operation returned error on server : #" + mMac).c_str());
            }
        } else {
            LOGD(("Discovering services from server : #" + mMac).c_str());
            unique_lock<mutex> vUniqueLock(w->mMutex);
            ret = !mBluetoothGatt->discoverServices();
            w->mConditionServicesDiscovered.wait_for(vUniqueLock, 300000*w->mMili);
            vUniqueLock.unlock();

            if (ret) {
                LOGD(("Write failed because service discovery returned error on server : #" + mMac).c_str());
            }
        }
        if (ret) {
            LOGD(("Removing server : #" + mMac).c_str());
            mBluetoothGatt->disconnect();
        }
    } else {
        unique_lock<mutex> vUniqueLock(w->mMutex);
        ret = !w->mBluetoothGattServer->notifyCharacteristicChanged(mBluetoothDevice, w->mBluetoothGattCharacteristic, true);

        if (ret) {
            // HINT: unique_lock would also unlock the managed mutex on destruction, even if not called explicitly
            vUniqueLock.unlock();
            // END critical section

            LOGD(("Notification failed for client : #" + mMac).c_str());
            //FIXME: force close client BluetoothDevice?
            //mBluetoothGattServer cancelConnection (BluetoothDevice device)
        } else {
            LOGD(("Sending Notification to client : #" + mMac).c_str());
            // The current thread shall have locked mMutex before calling wait_for
            w->mConditionNotificationSent.wait_for(vUniqueLock, 20000*w->mMili);
            // At the moment of blocking the thread, wait_for calls mMutex.unlock()
            // END critical section

            // Mutex is unlocked, but thread is blocked by wait_for until notification or timeout
            // Once notified, thread is running again and wait_for calls mMutex.lock()

            // BEGIN critical section
            // HINT: unique_lock would also unlock the managed mutex on destruction, even if not called explicitly
            vUniqueLock.unlock();
            // END critical section
        }
    }
    return ret;
}

} // End namespace
