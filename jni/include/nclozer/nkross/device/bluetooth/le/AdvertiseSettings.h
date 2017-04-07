#ifndef __AdvertiseSettings_H__
#define __AdvertiseSettings_H__

namespace NSDEVICE
{

class AdvertiseSettings : public Object
{
friend NSNATIVE::NKrossFriend;

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
            NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNPhi00, (NParam)this);
        }

        AdvertiseSettings* build()
        {
            AdvertiseSettings* b = NKrossWrapper::w->mNKrossFriend->pointer<AdvertiseSettings>();
            return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this, (NParam)b));
        }

        AdvertiseSettings::Builder* setConnectable(bool connectable)
        {
            NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNKhi00, (NParam)this, (NParam)connectable);
            return this;
        }

        AdvertiseSettings::Builder* setTimeout(int timeoutMillis)
        {
            NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNPsi00, (NParam)this, (NParam)timeoutMillis);
            return this;
        }

        AdvertiseSettings::Builder* setTxPowerLevel(int txPowerLevel)
        {
            NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNOmega00, (NParam)this, (NParam)txPowerLevel);
            return this;
        }
    };

    ~AdvertiseSettings()
    {
    }

    int getMode()
    {
        return NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNGamma00, (NParam)this);
    }

    int getTimeout()
    {
        return NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }

    bool isConnectable()
    {
        return (bool)NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this);
    }

private:
    AdvertiseSettings(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
