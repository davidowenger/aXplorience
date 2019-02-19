#ifndef __Context_H__
#define __Context_H__

namespace NSDEVICE
{

class Context : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const String BLUETOOTH_SERVICE;
    static const String LOCATION_SERVICE;

    virtual ~Context()
    {
    }

    virtual Object* getSystemService(const String& name)
    {
        Object* b = nullptr;

        if (name == Context::BLUETOOTH_SERVICE) {
            b = (Object*)NSNKROSS::w->mNKrossFriend->pointer<BluetoothManager>();
        }
        if (name == Context::LOCATION_SERVICE) {
            b = (Object*)NSNKROSS::w->mNKrossFriend->pointer<LocationManager>();
        }
        if (b) {
            b = NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorContent->tRun(NSNKROSS::w->mNGamma00, (NParam)this, (NParam)b, NKrossParam(name).n));
        }
        return b;
    }

private:
    Context(NKrossFriend* vNKrossFriend)
    {
    }

};

} // End namespace

#endif
