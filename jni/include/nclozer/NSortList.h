#ifndef __NSortList_H__
#define __NSortList_H__

namespace NSDEVICE
{

template <class T, typename U>
class NSortListItem
{
public:
    NSortListItem()
        : mObject{}, mValue(0)
    {
        mNext = this;
    }

   ~NSortListItem()
    {
    }

    T mObject;
    U mValue;
    NSortListItem<T, U>* mNext;
};

template <class T, typename U>
class NSortList
{
public:
    NSortList() :
        mSize(0),
        mHeadItem(new NSortListItem<T, U>()),
        mTailItem(new NSortListItem<T, U>()),
        mLastItem(new NSortListItem<T, U>())
    {
        mHeadItem->mNext = mTailItem;
        mTailItem->mNext = mLastItem;
    }

   ~NSortList()
    {
        NSortListItem<T, U>* vItem;

        while ((vItem = mHeadItem)) {
            mHeadItem = ( vItem != vItem->mNext ? vItem->mNext : nullptr );
            delete vItem;
        }
    }

    void add(nint vSize)
    {
        while (vSize--) {
            NSortListItem<T, U>* vItem;
            vItem = new NSortListItem<T, U>();
            vItem->mNext = mHeadItem->mNext;
            mHeadItem->mNext = vItem;
            ++mSize;
        }
    }

    void add(T vObject, U vValue)
    {
        NSortListItem<T, U>* vCurrentItem;
        NSortListItem<T, U>* vPreviousItem = mHeadItem;

        while (vPreviousItem->mNext->mValue <= vValue && vPreviousItem->mNext != mTailItem) {
            vPreviousItem = vPreviousItem->mNext;
        }
        vCurrentItem = new NSortListItem<T, U>();
        vCurrentItem->mObject = vObject;
        vCurrentItem->mValue = vValue;
        vCurrentItem->mNext = vPreviousItem->mNext;
        vPreviousItem->mNext = vCurrentItem;
        ++mSize;
    }

    T getObject()
    {
        return mHeadItem->mNext->mObject;
    }

    U getValue()
    {
        return mHeadItem->mNext->mValue;
    }

    void remove(T vObject)
    {
        NSortListItem<T, U>* vCurrentItem;
        NSortListItem<T, U>* vPreviousItem = mHeadItem;

        while (vPreviousItem->mNext->mObject != vObject && vPreviousItem->mNext != mTailItem) {
            vPreviousItem = vPreviousItem->mNext;
        }
        vCurrentItem = vPreviousItem->mNext;

        if (vCurrentItem != mTailItem) {
            vPreviousItem->mNext = vCurrentItem->mNext;
            delete vCurrentItem;
            --mSize;
        }
    }

    void remove(nint vSize)
    {
        while (vSize--) {
            NSortListItem<T, U>* vItem;
            vItem = mHeadItem->mNext;
            mHeadItem->mNext = vItem->mNext;
            delete vItem;
            --mSize;
        }
    }

    void resize(nint vSize)
    {
        if (vSize - mSize >= 0) {
            add(vSize - mSize);
        } else {
            remove(mSize - vSize);
        }
    }

    T updateObject(T vObject, U vValue)
    {
        NSortListItem<T, U>* vCurrentItem;
        NSortListItem<T, U>* vPreviousItem = mTailItem;

        while (vPreviousItem->mNext->mValue <= vValue && vPreviousItem->mNext != mLastItem) {
            vPreviousItem = vPreviousItem->mNext;
        }
        vCurrentItem = mHeadItem->mNext;
        mHeadItem->mNext = vCurrentItem->mNext;
        vCurrentItem->mObject = vObject;
        vCurrentItem->mValue = vValue;
        vCurrentItem->mNext = vPreviousItem->mNext;
        vPreviousItem->mNext = vCurrentItem;
        return swap();
    }

    T updateValue(U vValue)
    {
        NSortListItem<T, U>* vCurrentItem;
        NSortListItem<T, U>* vPreviousItem = mTailItem;

        while (vPreviousItem->mNext->mValue <= vValue && vPreviousItem->mNext != mLastItem) {
            vPreviousItem = vPreviousItem->mNext;
        }
        vCurrentItem = mHeadItem->mNext;
        mHeadItem->mNext = vCurrentItem->mNext;
        vCurrentItem->mValue = vValue;
        vCurrentItem->mNext = vPreviousItem->mNext;
        vPreviousItem->mNext = vCurrentItem;
        return swap();
    }

    T swap()
    {
        T vNextObject = mHeadItem->mNext->mObject;

        if (mHeadItem->mNext == mTailItem) {
            mHeadItem->mNext = mTailItem->mNext;
            mLastItem->mNext = mTailItem;
            mTailItem = mLastItem;
            mLastItem = mLastItem->mNext;
            mLastItem->mNext = mLastItem;
        }
        return vNextObject;
    }

    nint mSize;
    NSortListItem<T, U>* mHeadItem;
    NSortListItem<T, U>* mTailItem;
    NSortListItem<T, U>* mLastItem;
};

} // End namespace

#endif
