#ifndef __NVec_H__
#define __NVec_H__

namespace NSNATIVE
{

template <typename T>
class NVec
{
public:
    NVec<T>() :
        d(nullptr)
    {
    }

    NVec<T>(nuint vSize) :
        d(new T[vSize]())
    {
    }

    NVec<T>(initializer_list<T> vInit) :
        d(new T[vInit.size()]())
    {
        nuint i = vInit.size();

        while (i--) {
            d[i] = *(vInit.begin() + i);
        }
    }

   ~NVec<T>()
    {
    }

    T operator[](nuint vIndex)
    {
        return d[vIndex];
    }

    void discard()
    {
        if (d) {
            delete[] d;
        }
    }

    NVec<T> add1(NVec<T> vNVec)
    {
        d[0] += vNVec.d[0];
        return *this;
    }

    NVec<T> is(T v0)
    {
        d[0] = v0;
        return *this;
    }

    NVec<T> is1(T* vaData)
    {
        d[0] = vaData[0];
        return *this;
    }

    NVec<T> is1(NVec<T>& vNVec)
    {
        d[0] = vNVec.d[0];
        return *this;
    }

    NVec<T> scale1(T vScale)
    {
        d[0] *= vScale;
        return *this;
    }

    NVec<T> sub1(NVec<T> vNVec)
    {
        d[0] -= vNVec.d[0];
        return *this;
    }

    NVec<T> add2(NVec<T> vNVec)
    {
        d[0] += vNVec.d[0];
        d[1] += vNVec.d[1];
        return *this;
    }

    T angle2()
    {
        return atan2(d[1], d[0]);
    }

    T angle2(NVec<T> vVector)
    {
        return fmod(atan2(vVector.d[1], vVector.d[0]) - atan2(d[1], d[0]) + 3.0f*M_PI, 2.0f*M_PI) - M_PI;
    }

    T dot2(NVec<T> vVector)
    {
        return d[0]*vVector.d[0] + d[1]*vVector.d[1];
    }

    NVec<T> is(T v0, T v1)
    {
        d[0] = v0;
        d[1] = v1;
        return *this;
    }

    NVec<T> is2(T* vaData)
    {
        d[0] = vaData[0];
        d[1] = vaData[1];
        return *this;
    }

    NVec<T> is2(NVec<T> vNVec)
    {
        d[0] = vNVec.d[0];
        d[1] = vNVec.d[1];
        return *this;
    }

    T magnitude2()
    {
        return sqrt(d[0]*d[0] + d[1]*d[1]);
    }

    NVec<T> scale2(T vScale)
    {
        d[0] *= vScale;
        d[1] *= vScale;
        return *this;
    }

    NVec<T> sub2(NVec<T> vNVec)
    {
        d[0] -= vNVec.d[0];
        d[1] -= vNVec.d[1];
        return *this;
    }

    NVec<T> unit2()
    {
        // No zero division check - <this> must be non-zero
        T n = magnitude2();
        d[0] /= n;
        d[1] /= n;
        return *this;
    }

    NVec<T> add3(NVec<T> vNVec)
    {
        d[0] += vNVec.d[0];
        d[1] += vNVec.d[1];
        d[2] += vNVec.d[2];
        return *this;
    }

    T angle3(NVec<T> vVector1, NVec<T> vVector2)
    {
        // <this> is the "up" axis of the observer orientation
        // Angle sign is based on the mixed product of the three vectors
        // No zero division check - <vVector1> and <vVector2> must be non-zero
        T vSign = 1 - 2*(mix(vVector1, vVector2) < 0);
        return acos(vVector1.dot3(vVector2)/sqrt(vVector1.dot3(vVector1)*vVector2.dot3(vVector2)))*vSign;
    }

    NVec<T> cross3(NVec<T> vVector)
    {
        T t[3] {
            d[1]*vVector.d[2] - d[2]*vVector.d[1],
            d[2]*vVector.d[0] - d[0]*vVector.d[2],
            d[0]*vVector.d[1] - d[1]*vVector.d[0]
        };
        return this->is3(t);
    }

    T dot3(NVec<T> vVector)
    {
        return d[0]*vVector.d[0] + d[1]*vVector.d[1] + d[2]*vVector.d[2];
    }

    NVec<T> is(T v0, T v1, T v2)
    {
        d[0] = v0;
        d[1] = v1;
        d[2] = v2;
        return *this;
    }

    NVec<T> is3(T* vaData)
    {
        d[0] = vaData[0];
        d[1] = vaData[1];
        d[2] = vaData[2];
        return *this;
    }

    NVec<T> is3(NVec<T> vNVec)
    {
        d[0] = vNVec.d[0];
        d[1] = vNVec.d[1];
        d[2] = vNVec.d[2];
        return *this;
    }

    T magnitude3()
    {
        return sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);
    }

    T mix3(NVec<T> vVector1, NVec<T> vVector2)
    {
        return
            (d[0]*(vVector1.d[1]*vVector2.d[2] - vVector1.d[2]*vVector2.d[1]) +
             d[1]*(vVector1.d[2]*vVector2.d[0] - vVector1.d[0]*vVector2.d[2]) +
             d[2]*(vVector1.d[0]*vVector2.d[1] - vVector1.d[1]*vVector2.d[0]));
    }

    NVec<T> mul3AtLeft(NVec<T> vMatrix)
    {
        T t[3] {
            vMatrix.d[0]*d[0] + vMatrix.d[3]*d[1] + vMatrix.d[6]*d[2],
            vMatrix.d[1]*d[0] + vMatrix.d[4]*d[1] + vMatrix.d[7]*d[2],
            vMatrix.d[2]*d[0] + vMatrix.d[5]*d[1] + vMatrix.d[8]*d[2]
        };
        return this->is3(t);
    }

    NVec<T> scale3(T vScale)
    {
        d[0] *= vScale;
        d[1] *= vScale;
        d[2] *= vScale;
        return *this;
    }

    NVec<T> sub3(NVec<T> vNVec)
    {
        d[0] -= vNVec.d[0];
        d[1] -= vNVec.d[1];
        d[2] -= vNVec.d[2];
        return *this;
    }

    NVec<T> unit3()
    {
        // No zero division check - <this> must be non-zero
        T n = magnitude3();
        d[0] /= n;
        d[1] /= n;
        d[2] /= n;
        return *this;
    }

    NVec<T> add4(NVec<T> vNVec)
    {
        d[0] += vNVec.d[0];
        d[1] += vNVec.d[1];
        d[2] += vNVec.d[2];
        d[3] += vNVec.d[3];
        return *this;
    }

    NVec<T> conj4()
    {
        d[0] = -d[0];
        d[1] = -d[1];
        d[2] = -d[2];
        return *this;
    }

    NVec<T> is(T v0, T v1, T v2, T v3)
    {
        d[0] = v0;
        d[1] = v1;
        d[2] = v2;
        d[3] = v3;
        return *this;
    }

    NVec<T> is4(T* vaData)
    {
        d[0] = vaData[0];
        d[1] = vaData[1];
        d[2] = vaData[2];
        d[3] = vaData[3];
        return *this;
    }

    NVec<T> is4(NVec<T> vNVec)
    {
        d[0] = vNVec.d[0];
        d[1] = vNVec.d[1];
        d[2] = vNVec.d[2];
        d[3] = vNVec.d[3];
        return *this;
    }

    NVec<T> is4FromAxisAngle(NVec<T> vRotationAxis, T vRotationAngle)
    {
        // Axis magnitude must be 1
        vRotationAngle /= 2;
        d[3] = cos(vRotationAngle);
        vRotationAngle = sin(vRotationAngle);
        d[2] = vRotationAxis.d[2]*vRotationAngle;
        d[1] = vRotationAxis.d[1]*vRotationAngle;
        d[0] = vRotationAxis.d[0]*vRotationAngle;
        return *this;
    }

    NVec<T> mul4(NVec<T> vQuat)
    {
        T t[4] {
            d[3]*vQuat.d[0] + d[0]*vQuat.d[3] + d[1]*vQuat.d[2] - d[2]*vQuat.d[1],
            d[3]*vQuat.d[1] + d[1]*vQuat.d[3] + d[2]*vQuat.d[0] - d[0]*vQuat.d[2],
            d[3]*vQuat.d[2] + d[2]*vQuat.d[3] + d[0]*vQuat.d[1] - d[1]*vQuat.d[0],
            d[3]*vQuat.d[3] - d[0]*vQuat.d[0] - d[1]*vQuat.d[1] - d[2]*vQuat.d[2]
        };
        return *this;
    }

    NVec<T> mul4AtLeft(NVec<T> vQuat)
    {
        T t[4] {
            vQuat.d[3]*d[0] + vQuat.d[0]*d[3] + vQuat.d[1]*d[2] - vQuat.d[2]*d[1],
            vQuat.d[3]*d[1] + vQuat.d[1]*d[3] + vQuat.d[2]*d[0] - vQuat.d[0]*d[2],
            vQuat.d[3]*d[2] + vQuat.d[2]*d[3] + vQuat.d[0]*d[1] - vQuat.d[1]*d[0],
            vQuat.d[3]*d[3] - vQuat.d[0]*d[0] - vQuat.d[1]*d[1] - vQuat.d[2]*d[2]
        };
        return this->is4(t);
    }

    NVec<T> mul4ByAxisAngle(NVec<T> vRotationAxis, T vRotationAngle)
    {
        // Axis magnitude must be 1
        T q[4];
        vRotationAngle /= 2;
        q[3] = cos(vRotationAngle);
        vRotationAngle = sin(vRotationAngle);
        q[2] = vRotationAxis.d[2]*vRotationAngle;
        q[1] = vRotationAxis.d[1]*vRotationAngle;
        q[0] = vRotationAxis.d[0]*vRotationAngle;
        T t[4] {
            d[3]*q[0] + d[0]*q[3] + d[1]*q[2] - d[2]*q[1],
            d[3]*q[1] + d[1]*q[3] + d[2]*q[0] - d[0]*q[2],
            d[3]*q[2] + d[2]*q[3] + d[0]*q[1] - d[1]*q[0],
            d[3]*q[3] - d[0]*q[0] - d[1]*q[1] - d[2]*q[2]
        };
        return this->is4(t);
    }

    NVec<T> rot3(NVec<T> vRotationQuat)
    {
        // Rotation must be a unit quaternion
        T t[4] {
           d[0]*vRotationQuat.d[3] - d[1]*vRotationQuat.d[2] + d[2]*vRotationQuat.d[1],
           d[1]*vRotationQuat.d[3] - d[2]*vRotationQuat.d[0] + d[0]*vRotationQuat.d[2],
           d[2]*vRotationQuat.d[3] - d[0]*vRotationQuat.d[1] + d[1]*vRotationQuat.d[0],
           d[0]*vRotationQuat.d[0] + d[1]*vRotationQuat.d[1] + d[2]*vRotationQuat.d[2]
        };
        d[0] = vRotationQuat.d[3]*t[0] + vRotationQuat.d[0]*t[3] + vRotationQuat.d[1]*t[2] - vRotationQuat.d[2]*t[1];
        d[1] = vRotationQuat.d[3]*t[1] + vRotationQuat.d[1]*t[3] + vRotationQuat.d[2]*t[0] - vRotationQuat.d[0]*t[2];
        d[2] = vRotationQuat.d[3]*t[2] + vRotationQuat.d[2]*t[3] + vRotationQuat.d[0]*t[1] - vRotationQuat.d[1]*t[0];
        return *this;
    }

    NVec<T> rot4(NVec<T> vRotationQuat)
    {
        // Rotation must be a unit quaternion
        T t[4] {
           -d[3]*vRotationQuat.d[0] + d[0]*vRotationQuat.d[3] - d[1]*vRotationQuat.d[2] + d[2]*vRotationQuat.d[1],
           -d[3]*vRotationQuat.d[1] + d[1]*vRotationQuat.d[3] - d[2]*vRotationQuat.d[0] + d[0]*vRotationQuat.d[2],
           -d[3]*vRotationQuat.d[2] + d[2]*vRotationQuat.d[3] - d[0]*vRotationQuat.d[1] + d[1]*vRotationQuat.d[0],
            d[3]*vRotationQuat.d[3] + d[0]*vRotationQuat.d[0] + d[1]*vRotationQuat.d[1] + d[2]*vRotationQuat.d[2]
        };
        d[0] = vRotationQuat.d[3]*t[0] + vRotationQuat.d[0]*t[3] + vRotationQuat.d[1]*t[2] - vRotationQuat.d[2]*t[1];
        d[1] = vRotationQuat.d[3]*t[1] + vRotationQuat.d[1]*t[3] + vRotationQuat.d[2]*t[0] - vRotationQuat.d[0]*t[2];
        d[2] = vRotationQuat.d[3]*t[2] + vRotationQuat.d[2]*t[3] + vRotationQuat.d[0]*t[1] - vRotationQuat.d[1]*t[0];
        d[3] = vRotationQuat.d[3]*t[3] - vRotationQuat.d[0]*t[0] - vRotationQuat.d[1]*t[1] - vRotationQuat.d[2]*t[2];
        return *this;
    }

    NVec<T> rot3ByAxisAngle(NVec<T> vRotationAxis, T vRotationAngle)
    {
        // Axis magnitude must be 1
        T q[4];
        vRotationAngle /= 2;
        q[3] = cos(vRotationAngle);
        vRotationAngle = sin(vRotationAngle);
        q[2] = vRotationAxis.d[2]*vRotationAngle;
        q[1] = vRotationAxis.d[1]*vRotationAngle;
        q[0] = vRotationAxis.d[0]*vRotationAngle;
        T t[4] {
           d[0]*q[3] - d[1]*q[2] + d[2]*q[1],
           d[1]*q[3] - d[2]*q[0] + d[0]*q[2],
           d[2]*q[3] - d[0]*q[1] + d[1]*q[0],
           d[0]*q[0] + d[1]*q[1] + d[2]*q[2]
        };
        d[0] = q[3]*t[0] + q[0]*t[3] + q[1]*t[2] - q[2]*t[1];
        d[1] = q[3]*t[1] + q[1]*t[3] + q[2]*t[0] - q[0]*t[2];
        d[2] = q[3]*t[2] + q[2]*t[3] + q[0]*t[1] - q[1]*t[0];
        return *this;
    }

    NVec<T> rot4ByAxisAngle(NVec<T> vRotationAxis, T vRotationAngle)
    {
        // Axis must be a unit vector
        vRotationAngle /= 2;
        T q[4];
        q[3] = cos(vRotationAngle);
        vRotationAngle = sin(vRotationAngle);
        q[2] = vRotationAxis.d[2]*vRotationAngle;
        q[1] = vRotationAxis.d[1]*vRotationAngle;
        q[0] = vRotationAxis.d[0]*vRotationAngle;
        T t[4] {
           -d[3]*q[0] + d[0]*q[3] - d[1]*q[2] + d[2]*q[1],
           -d[3]*q[1] + d[1]*q[3] - d[2]*q[0] + d[0]*q[2],
           -d[3]*q[2] + d[2]*q[3] - d[0]*q[1] + d[1]*q[0],
            d[3]*q[3] + d[0]*q[0] + d[1]*q[1] + d[2]*q[2]
        };
        d[0] = q[3]*t[0] + q[0]*t[3] + q[1]*t[2] - q[2]*t[1];
        d[1] = q[3]*t[1] + q[1]*t[3] + q[2]*t[0] - q[0]*t[2];
        d[2] = q[3]*t[2] + q[2]*t[3] + q[0]*t[1] - q[1]*t[0];
        d[3] = q[3]*t[3] - q[0]*t[0] - q[1]*t[1] - q[2]*t[2];
        return *this;
    }

    T magnitude4()
    {
        return sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2] + d[3]*d[3]);
    }

    NVec<T> scale4(T vScale)
    {
        d[0] *= vScale;
        d[1] *= vScale;
        d[2] *= vScale;
        d[3] *= vScale;
        return *this;
    }

    NVec<T> sub4(NVec<T> vNVec)
    {
        d[0] -= vNVec.d[0];
        d[1] -= vNVec.d[1];
        d[2] -= vNVec.d[2];
        d[3] -= vNVec.d[3];
        return *this;
    }

    NVec<T> unit4()
    {
        // No zero division check - <this> must be non-zero
        T n = magnitude4();
        d[0] /= n;
        d[1] /= n;
        d[2] /= n;
        d[3] /= n;
        return *this;
    }

    NVec<T> add9(NVec<T> vMatrix)
    {
        d[0] += vMatrix.d[0];
        d[1] += vMatrix.d[1];
        d[2] += vMatrix.d[2];
        d[3] += vMatrix.d[3];
        d[4] += vMatrix.d[3];
        d[5] += vMatrix.d[5];
        d[6] += vMatrix.d[6];
        d[7] += vMatrix.d[7];
        d[8] += vMatrix.d[8];
        return *this;
    }

    T det9()
    {
        return
            (d[0]*(d[4]*d[8] - d[5]*d[7]) +
             d[1]*(d[5]*d[6] - d[3]*d[8]) +
             d[2]*(d[3]*d[7] - d[4]*d[6]));
    }

    NVec<T> inv9()
    {
        T vDet = det9();
        T t[9] {
            (d[4]*d[8] - d[7]*d[5])/vDet,
           -(d[1]*d[8] - d[7]*d[2])/vDet,
            (d[1]*d[5] - d[4]*d[2])/vDet,
           -(d[3]*d[8] - d[6]*d[5])/vDet,
            (d[0]*d[8] - d[6]*d[2])/vDet,
           -(d[0]*d[5] - d[3]*d[2])/vDet,
            (d[3]*d[7] - d[6]*d[4])/vDet,
           -(d[0]*d[7] - d[6]*d[1])/vDet,
            (d[0]*d[4] - d[3]*d[1])/vDet
        };
        return this->is9(t);
    }

    NVec<T> is(T v0, T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8)
    {
        d[0] = v0;
        d[1] = v3;
        d[2] = v6;
        d[3] = v1;
        d[4] = v4;
        d[5] = v7;
        d[6] = v2;
        d[7] = v5;
        d[8] = v8;
        return *this;
    }

    NVec<T> is9(T* vaData)
    {
        d[0] = vaData[0];
        d[1] = vaData[1];
        d[2] = vaData[2];
        d[3] = vaData[3];
        d[4] = vaData[4];
        d[5] = vaData[5];
        d[6] = vaData[6];
        d[7] = vaData[7];
        d[8] = vaData[8];
        return *this;
    }

    NVec<T> is9(NVec<T> vMatrix)
    {
        d[0] = vMatrix.d[0];
        d[1] = vMatrix.d[1];
        d[2] = vMatrix.d[2];
        d[3] = vMatrix.d[3];
        d[4] = vMatrix.d[4];
        d[5] = vMatrix.d[5];
        d[6] = vMatrix.d[6];
        d[7] = vMatrix.d[7];
        d[8] = vMatrix.d[8];
        return *this;
    }

    NVec<T> is(T v0, T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8, T v9, T v10, T v11, T v12, T v13, T v14, T v15)
    {
        d[0] = v0;
        d[1] = v4;
        d[2] = v8;
        d[3] = v12;
        d[4] = v1;
        d[5] = v5;
        d[6] = v9;
        d[7] = v13;
        d[8] = v2;
        d[9] = v6;
        d[10] = v10;
        d[11] = v14;
        d[12] = v3;
        d[13] = v7;
        d[14] = v11;
        d[15] = v15;
        return *this;
    }

    NVec<T> is16(T* vaData)
    {
        d[0] = vaData[0];
        d[1] = vaData[1];
        d[2] = vaData[2];
        d[3] = vaData[3];
        d[4] = vaData[4];
        d[5] = vaData[5];
        d[6] = vaData[6];
        d[7] = vaData[7];
        d[8] = vaData[8];
        d[9] = vaData[9];
        d[10] = vaData[10];
        d[11] = vaData[11];
        d[12] = vaData[12];
        d[13] = vaData[13];
        d[14] = vaData[14];
        d[15] = vaData[15];
        return *this;
    }

    NVec<T> is16(NVec<T> vMatrix)
    {
        d[0] = vMatrix.d[0];
        d[1] = vMatrix.d[1];
        d[2] = vMatrix.d[2];
        d[3] = vMatrix.d[3];
        d[4] = vMatrix.d[4];
        d[5] = vMatrix.d[5];
        d[6] = vMatrix.d[6];
        d[7] = vMatrix.d[7];
        d[8] = vMatrix.d[8];
        d[9] = vMatrix.d[9];
        d[10] = vMatrix.d[10];
        d[11] = vMatrix.d[11];
        d[12] = vMatrix.d[12];
        d[13] = vMatrix.d[13];
        d[14] = vMatrix.d[14];
        d[15] = vMatrix.d[15];
        return *this;
    }

    T* d;
};

} // End namespace

#endif
