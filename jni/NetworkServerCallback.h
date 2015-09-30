#ifndef __NetworkServerCallback_H__
#define __NetworkServerCallback_H__

namespace NSDEVICE
{

class NetworkServerCallback : public BluetoothGattServerCallback
{

public:
    NetworkServerCallback(Wrapper* vWrapper)
        : w(vWrapper)
    {
    }

    virtual ~NetworkServerCallback()
    {
    }

    // A remote client has requested to write to a local characteristic.
    // An application must call BluetoothGattServer::sendResponse(BluetoothDevice, int, int, int, byte[]) to complete the request.
    virtual void onCharacteristicWriteRequest(
        BluetoothDevice* device,
        int requestId,
        BluetoothGattCharacteristic* characteristic,
        bool preparedWrite,
        bool responseNeeded,
        int offset,
        NArray<nubyte> value
    ) {
        LOGD("Received write request");
        w->opUnitUI->sendOp(w->mOpUnitUIId, w->w->mNGamma00, new OpMessage(String((char*)(value.maData))));
    }

    virtual void onConnectionStateChange(BluetoothDevice* device, int status, int newState)
    {
        //DEBUG
        String vMac;
        try {
          vMac = regex_replace(device->getAddress(),regex("[^0123456789abcdefABCDEF]+"),String(""));
        }
        catch (regex_error& vError) {
            LOGE(("Regex error with code: #" + to_string<nuint>(vError.code())).c_str());
        }
        if (vMac == "E02A82CF0845" || vMac == "680571EDCCBE" || vMac == "E4B021A5443F" || vMac == "889B390B59E5") {
            LOGD(("Status from client : #" + to_string(status) + " new state : #" + to_string(newState)).c_str());
            w->mOpUnitNetwork->sendOp(w->mOpUnitNetworkId, w->w->mNEpsilon00, new OpParam((NParam)device, status, newState));
        }
    }

    virtual void onNotificationSent(BluetoothDevice* device, int status)
    {
        LOGD(("Notification sent to client : #" + to_string(status)).c_str());
        unique_lock<mutex> vUniqueLock(w->mMutex);
        w->mConditionNotificationSent.notify_all();
    }

    virtual void onServiceAdded(int status, BluetoothGattService* service)
    {
        LOGD(("Service added : #" + to_string(status)).c_str());
        unique_lock<mutex> vUniqueLock(w->mMutex);
        w->mConditionServicesAdded.notify_all();
    }

    Wrapper* w;
};

} // End namespace

#endif
