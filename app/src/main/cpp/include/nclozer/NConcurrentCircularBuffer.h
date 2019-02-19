#ifndef __NConcurrentCircularBuffer_H__
#define __NConcurrentCircularBuffer_H__

namespace NSDEVICE
{

// Lock-free concurrent Circular Buffer
// Items may be added in a circular buffer of size B by 1 producer thread and read by any thread
// Items must be consumed before B new items have been added
template <typename T>
class NConcurrentCircularBuffer
{
public:
    NConcurrentCircularBuffer(nuint vSize)
        : mSize(vSize), mHeadIndex(0), maBuffer(new T[mSize]())
    {
        nuint i;

        for ( i = 0 ; i < mSize ; ++i ) {
            maBuffer[i] = 0;
        }
    }

   ~NConcurrentCircularBuffer()
    {
        delete[] maBuffer;
    }

    void add(T vObject)
    {
        nuint vWriteNext = (mHeadIndex + 1)%mSize;
        maBuffer[vWriteNext] = vObject;
        mHeadIndex = vWriteNext;
    }

    T* getHead()
    {
        return maBuffer + mHeadIndex;
    }

    T readHead()
    {
        return maBuffer[mHeadIndex];
    }

    T read(nuint vIndex)
    {
        return maBuffer[vIndex];
    }

    nuint mSize;
    nuint mHeadIndex;
    T* maBuffer;
};

// Partial specialization of lock-free concurrent Circular Buffer for pointer types
// Pointers may be added in a circular buffer of size B by 1 producer thread and read by any thread
// Pointers must be consumed before B new pointers have been added, and are deleted automatically
template <typename T>
class NConcurrentCircularBuffer<T*>
{
public:
    NConcurrentCircularBuffer(nuint vSize, bool vAutoclean = false)
        : mAutoclean(vAutoclean), mSize(vSize), mHeadIndex(0), maBuffer(new T*[mSize]())
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
                if (maBuffer[i]) {
                    delete maBuffer[i];
                }
            }
        }
        delete[] maBuffer;
    }

    void add(T* vObject)
    {
        nuint vWriteNext = (mHeadIndex + 1)%mSize;
        T* vObjectRemoved = maBuffer[vWriteNext];
        maBuffer[vWriteNext] = vObject;
        mHeadIndex = vWriteNext;

        if (mAutoclean && vObjectRemoved) {
            delete vObjectRemoved;
        }
    }

    T** getHead()
    {
        return maBuffer + mHeadIndex;
    }

    T* readHead()
    {
        return maBuffer[mHeadIndex];
    }

    T* read(nuint vIndex)
    {
        return maBuffer[vIndex];
    }

    bool mAutoclean;
    nuint mSize;
    nuint mHeadIndex;
    T** maBuffer;
};

} // End namespace

#endif
