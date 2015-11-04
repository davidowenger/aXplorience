#ifndef __NConcurrentCircularBuffer_H__
#define __NConcurrentCircularBuffer_H__

namespace NSDEVICE
{

// Lock-free Concurrent Circular Buffer
// Items may be added in a circular buffer of size B by 1 producer thread and read by any thread
// Items must be consumed before B new items have been added
template <typename T>
class NConcurrentCircularBuffer
{
public:
    NConcurrentCircularBuffer(nuint vSize, bool vAutoclean = false)
        : mAutoclean(vAutoclean), mSize(vSize), mWriteIndex(0), maBuffer(new T[mSize]())
    {
        nuint i;

        for ( i = 0 ; i < mSize ; ++i ) {
            maBuffer[i] = 0;
        }
    }

   ~NConcurrentCircularBuffer()
    {
        nuint i;

        if (mAutoclean) {
            for ( i = 0 ; i < mSize ; ++i ) {
                if (mAutoclean && maBuffer[i]) {
                    delete maBuffer[i];
                }
            }
        }
        delete[] maBuffer;
    }

    void add(T vObject)
    {
        nuint vWriteNext = (mWriteIndex + 1)%mSize;
        T vObjectRemoved = maBuffer[vWriteNext];
        maBuffer[vWriteNext] = vObject;
        mWriteIndex = vWriteNext;

        if (mAutoclean && vObjectRemoved) {
            delete vObjectRemoved;
        }
    }

    T read()
    {
        return maBuffer[mWriteIndex];
    }

    T read(nuint vIndex)
    {
        return maBuffer[vIndex];
    }

    bool mAutoclean;
    nuint mSize;
    nuint mWriteIndex;
    T* maBuffer;
};

template <typename T>
class NConcurrentCircularScalarBuffer
{
public:
    NConcurrentCircularScalarBuffer(nuint vSize)
        : mSize(vSize), mWriteIndex(0), maBuffer(new T[mSize]())
    {
        nuint i;

        for ( i = 0 ; i < mSize ; ++i ) {
            maBuffer[i] = 0;
        }
    }

   ~NConcurrentCircularScalarBuffer()
    {
        delete[] maBuffer;
    }

    void add(T vObject)
    {
        nuint vWriteNext = (mWriteIndex + 1)%mSize;
        maBuffer[vWriteNext] = vObject;
        mWriteIndex = vWriteNext;
    }

    T read()
    {
        return maBuffer[mWriteIndex];
    }

    T read(nuint vIndex)
    {
        return maBuffer[vIndex];
    }

    nuint mSize;
    nuint mWriteIndex;
    T* maBuffer;
};

} // End namespace

#endif
