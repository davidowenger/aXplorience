#ifndef __Context_H__
#define __Context_H__

namespace NSDEVICE
{

class Context : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const String BLUETOOTH_SERVICE;

    virtual ~Context();

    virtual Object* getSystemService(const String& name);

private:
    Context(NNoObject* vNNoObject);
};

} // End namespace

#endif
