#ifndef __CircularConcurrentList_H__
#define __CircularConcurrentList_H__

namespace NSDEVICE
{

//Circular Concurrent List
template <typename T>
class ColItem
{
public:
    ColItem(T vObject, bool vAutoclean)
        : mObject(vObject), mAutoclean(vAutoclean)
    {
        mNext = this;
    }

    ~ColItem()
     {
        if (mAutoclean && mObject) {
            delete mObject;
        }
     }

    T mObject;
    bool mAutoclean;
    ColItem<T>* mNext;
};

template <typename T>
class Col
{
public:
    Col()
    {
        mItem = new ColItem<T>(nullptr, true);
        mLast = mItem;
    }

   ~Col()
    {
       ColItem<T>* vItem = nullptr;

       while ((vItem = mItem)) {
           mItem = ( vItem != vItem->mNext ? vItem->mNext : nullptr );
           delete vItem;
       }
    }

   void add(T vObject, bool vAutoclean = true)
   {
       // This function is thread-safe when used by 1 unique "source" prducer thread
       mLast->mNext = new ColItem<T>(vObject, vAutoclean);
       // Single pointer assignation is assumed to be atomic on the target plateform
       // This is true on X86 and ARM
       mLast = mLast->mNext;
   }

   void clear()
   {
       // This function is thread-safe when used by 1 unique "destination" thread
       ColItem<T>* vItem = nullptr;
       ColItem<T>* vItemTemp = mItem;

       mItem = new ColItem<T>(nullptr, true);
       // Single pointer assignation is assumed to be atomic on ARM plateforms
       mLast = mItem;

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
            ColItem<T>* vItem = mItem;
            mItem = vItem->mNext;
            vT = mItem->mObject;
            mItem->mObject = nullptr;
            delete vItem;
        }
        return vT;
    }

    ColItem<T>* mItem;
    ColItem<T>* mLast;
};

} // End namespace

#endif
