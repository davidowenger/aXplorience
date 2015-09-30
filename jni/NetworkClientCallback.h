#ifndef __NetworkClientCallback_H__
#define __NetworkClientCallback_H__

namespace NSDEVICE
{

class NetworkClientCallback : public BluetoothGattCallback
{
public:
    NetworkClientCallback(Wrapper* vWrapper, Peer* vPeer)
        : w(vWrapper), mServer(vPeer), mAlive(true)
    {
    }

    virtual ~NetworkClientCallback()
    {
    }

    virtual void onCharacteristicWrite(BluetoothGatt* gatt, BluetoothGattCharacteristic* characteristic, int status)
    {
        if (mAlive) {
            LOGD("Received data");
            w->opUnitUI->sendOp(w->mOpUnitUIId, w->w->mNGamma00, new OpMessage(characteristic->getStringValue(0)));
            unique_lock<mutex> vUniqueLock(w->mMutex);
            w->mConditionCharacteristicWrite.notify_all();
        }
    }

    virtual void onConnectionStateChange(BluetoothGatt* gatt, int status, int newState)
    {
        if (mAlive) {
            LOGD(("Status from server : #" + to_string(status) + " new state : #" + to_string(newState)).c_str());
            w->mOpUnitNetwork->sendOp(w->mOpUnitNetworkId, w->w->mNDzeta00, new OpParam((NParam)mServer, status, newState));
            unique_lock<mutex> vUniqueLock(w->mMutex);
            w->mConditionStateChange.notify_all();
        }
        if (!(status <= BluetoothGatt::STATE_CONNECTING && newState == BluetoothGatt::STATE_CONNECTED)) {
            mAlive = false;
        }
    }

    virtual void onServicesDiscovered(BluetoothGatt* gatt, int status)
    {
        if (mAlive) {
            LOGD("Received service");
            w->mOpUnitNetwork->sendOp(w->mOpUnitNetworkId, w->w->mNDelta00, new OpParam((NParam)mServer, status));
            unique_lock<mutex> vUniqueLock(w->mMutex);
            w->mConditionServicesDiscovered.notify_all();
        }
    }

    Wrapper* w;
    Peer* mServer;
    bool mAlive;
};

} // End namespace

#endif
