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
};

} // END namespace

#endif
