precision mediump float;
varying vec2 maFragment;

attribute vec3 vaVertex;
attribute vec2 vaFragment;
uniform vec4 vaRotation;
uniform vec3 vaTranslation;
uniform vec4 vaProjection;

void rot(inout vec3 vTargetVec, vec4 vRotationQuat)
{
    // Rotation must be a unit quaternion
    vec4 t = vec4(
       vTargetVec[0]*vRotationQuat[3] - vTargetVec[1]*vRotationQuat[2] + vTargetVec[2]*vRotationQuat[1],
       vTargetVec[1]*vRotationQuat[3] - vTargetVec[2]*vRotationQuat[0] + vTargetVec[0]*vRotationQuat[2],
       vTargetVec[2]*vRotationQuat[3] - vTargetVec[0]*vRotationQuat[1] + vTargetVec[1]*vRotationQuat[0],
       vTargetVec[0]*vRotationQuat[0] + vTargetVec[1]*vRotationQuat[1] + vTargetVec[2]*vRotationQuat[2]
    );
    vTargetVec[0] = vRotationQuat[3]*t[0] + vRotationQuat[0]*t[3] + vRotationQuat[1]*t[2] - vRotationQuat[2]*t[1];
    vTargetVec[1] = vRotationQuat[3]*t[1] + vRotationQuat[1]*t[3] + vRotationQuat[2]*t[0] - vRotationQuat[0]*t[2];
    vTargetVec[2] = vRotationQuat[3]*t[2] + vRotationQuat[2]*t[3] + vRotationQuat[0]*t[1] - vRotationQuat[1]*t[0];
}

void main()
{
    vec3 p = vec3(
        vaVertex.x,
       -vaVertex.z,
        vaVertex.y
    );
    rot(p, vaRotation);
    p.z = -vaTranslation.z - p.z;

    gl_Position = vec4(
        vaProjection.x*(vaTranslation.x/p.z + p.x),
        vaProjection.y*(vaTranslation.y/p.z + p.y),
        2.0*(p.z - vaProjection.z)/(vaProjection.w - vaProjection.z) - 1.0,
        1.0
    );
    maFragment = vaFragment;
}
