#ifndef __NNoObject_H__
#define __NNoObject_H__

namespace NSNATIVE
{

class NNoObject
{
public:
    NNoObject()
    {
    }

    virtual ~NNoObject()
    {
    }

    template <class T>
    T instance()
    {
        return T(this);
    }

    template <class T>
    T* pointer()
    {
        return new T(this);
    }

    template <class T>
    T* emplaceKey(T* vApplicationCallback, NReturn vUserCallback)
    {
        if ((NReturn)vApplicationCallback != vUserCallback) {
            // Unused pointers generated on-the-go by the application are deleted immediately
            delete vApplicationCallback;
            // This global object already has a callback pointer
            vApplicationCallback = (T*)vUserCallback;
        }
#ifdef DEBUG
        else {
            // A callback pointer has been generated and will have to be deleted by the user
            // Except for some Event* that may be deleted automatically after the end of the callback event function
            LOGV("Added one Application Callback pointer");
        }
#endif
        return vApplicationCallback;
    }
};

} // END namespace

#endif
