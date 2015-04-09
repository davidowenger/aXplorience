#ifndef __RootLayout_H__
#define __RootLayout_H__

namespace NSDEVICE
{

struct FragmentLayout
{
    nint mcView;
    nint mcPosition;
    nint mcPriority;
};

struct RootLayoutItem
{
    nint mcMaxLevel;
    FragmentLayout maFragmentLayout[3];
};

class RootLayout : public FrameLayout
{
public:
    RootLayout(Wrapper* w);
    virtual ~RootLayout() override;

    Wrapper* w;
};

} // End namespace

#endif
