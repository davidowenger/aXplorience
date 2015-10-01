#ifndef __AdvertiseSettings_H__
#define __AdvertiseSettings_H__

namespace NSDEVICE
{

class AdvertiseSettings : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int ADVERTISE_MODE_BALANCED = 0x00000001;
    static const int ADVERTISE_MODE_LOW_LATENCY = 0x00000002;
    static const int ADVERTISE_MODE_LOW_POWER = 0x00000000;
    static const int ADVERTISE_TX_POWER_HIGH = 0x00000003;
    static const int ADVERTISE_TX_POWER_LOW = 0x00000001;
    static const int ADVERTISE_TX_POWER_MEDIUM = 0x00000002;
    static const int ADVERTISE_TX_POWER_ULTRA_LOW = 0x00000000;

    class Builder
    {
    public:
        Builder()
        {
            NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNPhi00, (NParam)this);
        }

        AdvertiseSettings* build()
        {
            AdvertiseSettings* b = NWrapper::w->mNNoObject->pointer<AdvertiseSettings>();
            return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)b));
        }

        AdvertiseSettings::Builder* setConnectable(bool connectable)
        {
            NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNKhi00, (NParam)this, (NParam)connectable);
            return this;
        }

        AdvertiseSettings::Builder* setTimeout(int timeoutMillis)
        {
            NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNPsi00, (NParam)this, (NParam)timeoutMillis);
            return this;
        }

        AdvertiseSettings::Builder* setTxPowerLevel(int txPowerLevel)
        {
            NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNOmega00, (NParam)this, (NParam)txPowerLevel);
            return this;
        }
    };

    ~AdvertiseSettings()
    {
    }

    int getMode()
    {
        return NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNGamma00, (NParam)this);
    }

    int getTimeout()
    {
        return NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNDelta00, (NParam)this);
    }

    bool isConnectable()
    {
        return (bool)NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNEpsilon00, (NParam)this);
    }

private:
    AdvertiseSettings(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
