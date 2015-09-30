#include "native/NCommon.h"

namespace NSDEVICE
{

const String Context::BLUETOOTH_SERVICE = "bluetooth";

Context::Context(NNoObject* vNNoObject)
    : Object()
{
}

Context::~Context()
{
}

Object* Context::getSystemService(const String& name)
{
    Object* b = nullptr;

    if (name == Context::BLUETOOTH_SERVICE) {
        b = NWrapper::w->mNNoObject->pointer<BluetoothManager>();
    }
    if (b) {
        b = NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorContent->tRun(NWrapper::w->mNGamma00, (NParam)this, (NParam)b, NParamBox(NWrapper::w, name).n));
    }
    return b;
}

} // End namespace
