#ifndef __EditorInfo_H__
#define __EditorInfo_H__

namespace NSDEVICE
{

class EditorInfo
{
friend NSNATIVE::NKrossFriend;

public:
    static const int IME_ACTION_DONE = 6;
    static const int IME_ACTION_GO = 2;
    static const int IME_ACTION_NEXT = 5;
    static const int IME_ACTION_NONE = 1;
    static const int IME_ACTION_PREVIOUS = 7;
    static const int IME_ACTION_SEARCH = 3;
    static const int IME_ACTION_SEND = 4 ;
    static const int IME_ACTION_UNSPECIFIED = 0;

    static const int IME_FLAG_FORCE_ASCII = 0x80000000;
    static const int IME_FLAG_NAVIGATE_NEXT = 0x08000000;
    static const int IME_FLAG_NAVIGATE_PREVIOUS = 0x04000000;
    static const int IME_FLAG_NO_ACCESSORY_ACTION = 0x20000000;
    static const int IME_FLAG_NO_ENTER_ACTION = 0x40000000;
    static const int IME_FLAG_NO_EXTRACT_UI = 0x10000000;
    static const int IME_FLAG_NO_FULLSCREEN = 0x02000000;
    static const int IME_MASK_ACTION = 0x000000ff;
    static const int IME_NULL = 0x00000000;

    virtual ~EditorInfo()
    {
    }

protected:
    EditorInfo()
    {
    }

private:
    EditorInfo(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
