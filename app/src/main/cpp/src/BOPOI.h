#ifndef __BOPOI_H__
#define __BOPOI_H__

namespace NSDEVICE
{

class BOPOI
{
public:
    BOPOI(Wrapper* vWrapper, nfloat vLatitude, nfloat vLongitude, const String& vLabel, const String& vDescription);
    virtual ~BOPOI();

    Wrapper* w;
    nfloat* maEarthLocation;
    nfloat* maEarthCoord;

    String mLabel;
    String mDescription;
};

} // End namespace

#endif
