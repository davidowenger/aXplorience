#ifndef __NARRAY_H__
#define __NARRAY_H__

namespace NSNATIVE
{

template <typename T>
class NArray
{
public:
    NArray()
        : maData(nullptr), mcData(0)
    {
    }

    NArray(nuint vSize)
        : maData( vSize ? new T[vSize]() : nullptr ), mcData(vSize)
    {
    }

    NArray(initializer_list<T> vInit)
        : maData(new T[vInit.size()]()), mcData(vInit.size())
    {
        memcpy(maData, vInit.begin(), mcData*sizeof(T));
    }

    ~NArray()
    {
    }

    void discard()
    {
        if (maData) {
            delete[] maData;
        }
    }

    T* maData;
    nuint mcData;
};

} // End namespace

#endif
