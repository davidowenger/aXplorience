#ifndef __NSortList_H__
#define __NSortList_H__

namespace NSDEVICE
{

template <class T, typename U>
class NSortListItem
{
public:
    NSortListItem()
        : mObject(nullptr), mValue{}
    {
        mNext = this;
    }

   ~NSortListItem()
    {
    }

    T* mObject;
    U mValue;
    NSortListItem<T, U>* mNext;
};

template <class T, typename U>
class NSortList
{
public:
    NSortList() :
        mGet(0), mSet(1), mSize(0),
        mFirstItem(new NSortListItem<T, U>*[2] {new NSortListItem<T, U>(), new NSortListItem<T, U>()}),
        mHeadItem(new NSortListItem<T, U>*[2] {new NSortListItem<T, U>(), new NSortListItem<T, U>()}),
        mTailItem(new NSortListItem<T, U>*[2] {new NSortListItem<T, U>(), new NSortListItem<T, U>()})
    {
        mFirstItem[mGet]->mNext = mHeadItem[mGet];
        mHeadItem[mGet]->mNext = mTailItem[mGet];
        mFirstItem[mSet]->mNext = mHeadItem[mSet];
        mHeadItem[mSet]->mNext = mTailItem[mSet];
    }

   ~NSortList()
    {
        NSortListItem<T, U>* vItem;

        while ((vItem = mFirstItem[mGet])) {
            mFirstItem[mGet] = ( vItem != vItem->mNext ? vItem->mNext : nullptr );
            delete vItem;
        }
        while ((vItem = mFirstItem[mSet])) {
            mFirstItem[mSet] = ( vItem != vItem->mNext ? vItem->mNext : nullptr );
            delete vItem;
        }
    }

    T* updateHead()
    {
        return ( mHeadItem[mGet]->mNext != mTailItem[mGet] ? (mHeadItem[mGet] = mHeadItem[mGet]->mNext)->mObject : nullptr );
    };

    U updateValue(U vValue)
    {
        NSortListItem<T, U>* vCurrentItem;
        NSortListItem<T, U>* vPreviousItem = mHeadItem[mSet];

        while (vPreviousItem->mNext != mTailItem[mSet] && vPreviousItem->mNext->mValue < vValue) {
            vPreviousItem = vPreviousItem->mNext;
        }
        vCurrentItem = mFirstItem[mSet]->mNext;
        mFirstItem[mSet]->mNext = vCurrentItem->mNext;
        vCurrentItem->mObject = mHeadItem[mGet]->mObject;
        vCurrentItem->mValue = vValue;
        vCurrentItem->mNext = vPreviousItem->mNext;
        vPreviousItem->mNext = vCurrentItem;
        return mHeadItem[mGet]->mValue;
    };

    void resize(nint vSize)
    {
        if (vSize - mSize >= 0) {
            sizeAdd(vSize - mSize);
        } else {
            sizeSub(mSize - vSize);
        }
    }

    void setValue(T* vObject, U vValue)
    {
        NSortListItem<T, U>* vCurrentItem;
        NSortListItem<T, U>* vPreviousItem = mHeadItem[mSet];

        while (vPreviousItem->mNext != mTailItem[mSet] && vPreviousItem->mNext->mValue < vValue) {
            vPreviousItem = vPreviousItem->mNext;
        }
        vCurrentItem = mFirstItem[mSet]->mNext;
        mFirstItem[mSet]->mNext = vCurrentItem->mNext;
        vCurrentItem->mObject = vObject;
        vCurrentItem->mValue = vValue;
        vCurrentItem->mNext = vPreviousItem->mNext;
        vPreviousItem->mNext = vCurrentItem;
    }

    void sizeAdd(nint vSize)
    {
        while (vSize--) {
            NSortListItem<T, U>* vItem;
            vItem = new NSortListItem<T, U>();
            vItem->mNext = mFirstItem[mGet]->mNext;
            mFirstItem[mGet]->mNext = vItem;
            vItem = new NSortListItem<T, U>();
            vItem->mNext = mFirstItem[mSet]->mNext;
            mFirstItem[mSet]->mNext = vItem;
        }
    }

    void sizeSub(nint vSize)
    {
        while (vSize--) {
            NSortListItem<T, U>* vItem;
            vItem = mFirstItem[mGet]->mNext;
            mFirstItem[mGet]->mNext = vItem->mNext;
            delete vItem;
            vItem = mFirstItem[mSet]->mNext;
            mFirstItem[mSet]->mNext = vItem->mNext;
            delete vItem;
        }
    }

    void swap()
    {
        mGet = !mGet;
        mSet = !mSet;
    }

    nubyte mGet;
    nubyte mSet;
    nint mSize;
    NSortListItem<T, U>** mFirstItem;
    NSortListItem<T, U>** mHeadItem;
    NSortListItem<T, U>** mTailItem;
};

} // End namespace

#endif
