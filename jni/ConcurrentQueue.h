#ifndef __ConcurrentQueue_H__
#define __ConcurrentQueue_H__

namespace NSDEVICE
{

// Lock-free Concurrent Queue
// Items may be queued dynamically by 1 producer thread and removed by 1 consumer thread
template <typename T>
class ConcurrentQueueItem
{
public:
    ConcurrentQueueItem(T vObject, bool vAutoclean)
        : mObject(vObject), mAutoclean(vAutoclean)
    {
        mNext = this;
    }

    ~ConcurrentQueueItem()
     {
        if (mAutoclean && mObject) {
            delete mObject;
        }
     }

    T mObject;
    bool mAutoclean;
    ConcurrentQueueItem<T>* mNext;
};

template <typename T>
class ConcurrentQueue
{
public:
    ConcurrentQueue()
        : mAdded(0), mDeleted(0)
    {
        mItem = new ConcurrentQueueItem<T>(nullptr, true);
        mLast = mItem;
    }

   ~ConcurrentQueue()
    {
       ConcurrentQueueItem<T>* vItem = nullptr;

       while ((vItem = mItem)) {
           mItem = ( vItem != vItem->mNext ? vItem->mNext : nullptr );
           delete vItem;
       }
    }

   void add(T vObject, bool vAutoclean = true)
   {
       ConcurrentQueueItem<T>* vItem = new ConcurrentQueueItem<T>(vObject, vAutoclean);
       // This function is thread-safe when used by 1 unique "source" prducer thread
       mLast->mNext = vItem;
       // Single pointer assignation is assumed to be atomic on the target plateform
       // This is true on X86 and ARM
       mLast = vItem;
       ++mAdded;
   }

   void clear()
   {
       // This function is not thread-safe
       ConcurrentQueueItem<T>* vItem = nullptr;
       ConcurrentQueueItem<T>* vItemTemp = mItem;

       mItem = new ConcurrentQueueItem<T>(nullptr, true);
       mLast = mItem;
       mAdded = 0;
       mDeleted = 0;

       while ((vItem = vItemTemp)) {
           vItemTemp = ( vItem != vItem->mNext ? vItem->mNext : nullptr );
           delete vItem;
       }
    }

    T next()
    {
        // This function is thread-safe when used by 1 unique "destination" thread
        T vT = nullptr;

        if (mItem != mItem->mNext) {
            ConcurrentQueueItem<T>* vItem = mItem;
            mItem = vItem->mNext;
            ++mDeleted;
            vT = mItem->mObject;
            mItem->mObject = nullptr;
            delete vItem;
        }
        return vT;
    }

    nlong size()
    {
        return mAdded - mDeleted;
    }

    ConcurrentQueueItem<T>* mItem;
    ConcurrentQueueItem<T>* mLast;
    nlong mAdded;
    nlong mDeleted;
};

} // End namespace

#endif
