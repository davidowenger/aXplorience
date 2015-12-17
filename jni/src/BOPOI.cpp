#include "Common.h"

namespace NSDEVICE
{

BOPOI::BOPOI(Wrapper* vWrapper, nfloat vLatitude, nfloat vLongitude, const String& vLabel, const String& vDescription) :
    w(vWrapper), maEarthLocation(new nfloat[2] {vLatitude, vLongitude}), maEarthCoord(new nfloat[3]()),
     mLabel(vLabel), mDescription(vDescription)
{
    nfloat vLat = vLatitude*M_PI_180;
    nfloat vLong = vLongitude*M_PI_180;
    maEarthCoord[2] = sin(vLat);
    vLat = cos(vLat);
    maEarthCoord[1] = vLat*sin(vLong);
    maEarthCoord[0] = vLat*cos(vLong);
}

BOPOI::~BOPOI()
{
    delete[] maEarthLocation;
    delete[] maEarthCoord;
}

} // End namespace
