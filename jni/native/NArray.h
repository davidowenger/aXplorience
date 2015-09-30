#ifndef __NARRAY_H__
#define __NARRAY_H__

namespace NSDEVICE
{

template <typename T>
class NArray
{
public:
    NArray(nuint vSize)
        : mSize(vSize), maData(new T[vSize]())
    {
    }

    ~NArray()
    {
    }

    const nuint mSize;
    T* maData;
};

} // End namespace

#endif
