#ifndef __Sensor_H__
#define __Sensor_H__

namespace NSDEVICE
{

class Sensor : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const int TYPE_ACCELEROMETER = 0x00000001;
    static const int TYPE_ALL = 0xffffffff;
    static const int TYPE_AMBIENT_TEMPERATURE = 0x0000000d;
    static const int TYPE_GAME_ROTATION_VECTOR = 0x0000000f;
    static const int TYPE_GEOMAGNETIC_ROTATION_VECTOR = 0x00000014;
    static const int TYPE_GRAVITY = 0x00000009;
    static const int TYPE_GYROSCOPE = 0x00000004;
    static const int TYPE_GYROSCOPE_UNCALIBRATED = 0x00000010;
    static const int TYPE_HEART_RATE = 0x00000015;
    static const int TYPE_LIGHT = 0x00000005;
    static const int TYPE_LINEAR_ACCELERATION = 0x0000000a;
    static const int TYPE_MAGNETIC_FIELD = 0x00000002;
    static const int TYPE_MAGNETIC_FIELD_UNCALIBRATED = 0x0000000e;
    static const int TYPE_ORIENTATION = 0x00000003;
    static const int TYPE_PRESSURE = 0x00000006;
    static const int TYPE_PROXIMITY = 0x00000008;
    static const int TYPE_RELATIVE_HUMIDITY = 0x0000000c;
    static const int TYPE_ROTATION_VECTOR = 0x0000000b;
    static const int TYPE_SIGNIFICANT_MOTION = 0x00000011;
    static const int TYPE_STEP_COUNTER = 0x00000013;
    static const int TYPE_STEP_DETECTOR = 0x00000012;
    static const int TYPE_TEMPERATURE = 0x00000007;

    virtual ~Sensor()
    {
    }

private:
    Sensor(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
