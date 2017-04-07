#include "Common.h"

namespace NSDEVICE
{

EventManager::EventManager(Wrapper* const vWrapper) :
    w(vWrapper), mT0(0), mX0(0), mY0(0), mT(0), mX(0), mY(0), mState(1)
{
}

EventManager::~EventManager()
{
}

bool EventManager::onMove(View* vView, MotionEvent* event)
{
    bool vRet = false;

    switch (event->getActionMasked()) {
    case MotionEvent::ACTION_DOWN:
        mT = event->getEventTime();
        mX = event->getX();
        mY = event->getY();
        mT0 = mT;
        mX0 = mX;
        mY0 = mY;
        mState = (mState&0xFFFFFFFE) + 2;
        vRet = true;
        break;
    case MotionEvent::ACTION_POINTER_DOWN:
        mT = event->getEventTime();
        mX = event->getX();
        mY = event->getY();
        vRet = true;
        break;
    case MotionEvent::ACTION_MOVE:
        mT = event->getEventTime();
        mX = event->getX();
        mY = event->getY();
        vRet = true;
        break;
    case MotionEvent::ACTION_POINTER_UP:
        mT = event->getEventTime();
        mX = event->getX();
        mY = event->getY();
        vRet = true;
        break;
    case MotionEvent::ACTION_UP:
        mState = mState|1;
        vRet = true;
        break;
    case MotionEvent::ACTION_CANCEL:
        mT = 0;
        mState = mState|1;
        vRet = true;
        break;
    }
    return vRet;
}

//*******************************************************************************************//
//*************************************** OnTouchListener ***********************************//
//*******************************************************************************************//
bool EventManager::onTouch(View* vView, MotionEvent* event)
{
    bool vRet = false;

    switch (event->getActionMasked()) {
    case MotionEvent::ACTION_DOWN:
        mT = 1;
        mX = event->getX();
        mY = event->getY();
        mState = (mState&0xFFFFFFFE) + 2;
        vRet = true;
        break;
    case MotionEvent::ACTION_POINTER_DOWN:
        mX = event->getX();
        mY = event->getY();
        vRet = true;
        break;
    case MotionEvent::ACTION_MOVE:
        mX = event->getX();
        mY = event->getY();
        vRet = true;
        break;
    case MotionEvent::ACTION_POINTER_UP:
        mX = event->getX();
        mY = event->getY();
        vRet = true;
        break;
    case MotionEvent::ACTION_UP:
        mState = mState|1;
        vRet = true;
        break;
    case MotionEvent::ACTION_CANCEL:
        mT = 0;
        mState = mState|1;
        vRet = true;
        break;
    }
    return vRet;
}

} // End namespace
