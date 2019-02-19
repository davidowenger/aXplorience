#ifndef __NConcurrentQueue_H__
#define __NConcurrentQueue_H__

namespace NSNATIVE
{

// Lock-free Concurrent Queue
// Items may be queued dynamically by 1 producer thread and removed by 1 consumer thread
template <typename T>
class NConcurrentQueueItem
{
public:
    NConcurrentQueueItem(T vObject, bool vAutoclean)
        : mObject(vObject), mAutoclean(vAutoclean)
    {
        mNext = this;
    }

    ~NConcurrentQueueItem()
     {
        if (mAutoclean && mObject) {
            delete mObject;
        }
     }

    T mObject;
    bool mAutoclean;
    NConcurrentQueueItem<T>* mNext;
};

template <typename T>
class NConcurrentQueue
{
public:
    NConcurrentQueue()
        : mAdded(0), mDeleted(0)
    {
        mItem = new NConcurrentQueueItem<T>(nullptr, true);
        mLast = mItem;
    }

   ~NConcurrentQueue()
    {
       NConcurrentQueueItem<T>* vItem = nullptr;

       while ((vItem = mItem)) {
           mItem = ( vItem != vItem->mNext ? vItem->mNext : nullptr );
           delete vItem;
       }
    }

   void add(T vObject, bool vAutoclean = true)
   {
       NConcurrentQueueItem<T>* vItem = new NConcurrentQueueItem<T>(vObject, vAutoclean);
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
       NConcurrentQueueItem<T>* vItem = nullptr;
       NConcurrentQueueItem<T>* vItemTemp = mItem;

       mItem = new NConcurrentQueueItem<T>(nullptr, true);
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
            NConcurrentQueueItem<T>* vItem = mItem;
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

    NConcurrentQueueItem<T>* mItem;
    NConcurrentQueueItem<T>* mLast;
    nlong mAdded;
    nlong mDeleted;
};

} // End namespace

#endif
