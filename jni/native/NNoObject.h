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
        static Col<T*> maCol;
        if ((NReturn)vApplicationCallback != vUserCallback) {
            // Callback pointers initialized (with operator new) by the user have to be deleted by the user
            delete vApplicationCallback;
            vApplicationCallback = (T*)vUserCallback;
        } else {
            // Callback pointers sent to a listener (void onEvent(Event* e)) by the application will be implicitely deleted when the program quits
            //maCol.add(vApplicationCallback);
            LOGV("Added one Application Callback pointer");
        }
        return vApplicationCallback;
    }
};

} // END namespace

#endif
