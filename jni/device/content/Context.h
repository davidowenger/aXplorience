#ifndef __Context_H__
#define __Context_H__

namespace NSDEVICE
{

class Context : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const String BLUETOOTH_SERVICE;

    virtual ~Context()
    {
    }

    virtual Object* getSystemService(const String& name)
    {
        Object* b = nullptr;

        if (name == Context::BLUETOOTH_SERVICE) {
            b = (Object*)NWrapper::w->mNNoObject->pointer<BluetoothManager>();
        }
        if (b) {
            b = NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorContent->tRun(NWrapper::w->mNGamma00, (NParam)this, (NParam)b, NParamBox(NWrapper::w, name).n));
        }
        return b;
    }

private:
    Context(NNoObject* vNNoObject)
    {
    }

};

} // End namespace

#endif
