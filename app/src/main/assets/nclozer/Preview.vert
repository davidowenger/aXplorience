precision mediump float;
varying vec2 maFragment;

attribute vec3 vaVertex;
attribute vec2 vaFragment;
uniform float vcRotation;

void rotByAxisAngle(inout vec3 vTargetVec, vec3 vRotationAxis, float vRotationAngle)
{
    // Axis magnitude must be 1
    vec4 q;
    vRotationAngle /= 2.0;
    q[3] = cos(vRotationAngle);
    vRotationAngle = sin(vRotationAngle);
    q[2] = vRotationAxis[2]*vRotationAngle;
    q[1] = vRotationAxis[1]*vRotationAngle;
    q[0] = vRotationAxis[0]*vRotationAngle;
    vec4 t = vec4(
       vTargetVec[0]*q[3] - vTargetVec[1]*q[2] + vTargetVec[2]*q[1],
       vTargetVec[1]*q[3] - vTargetVec[2]*q[0] + vTargetVec[0]*q[2],
       vTargetVec[2]*q[3] - vTargetVec[0]*q[1] + vTargetVec[1]*q[0],
       vTargetVec[0]*q[0] + vTargetVec[1]*q[1] + vTargetVec[2]*q[2]
    );
    vTargetVec[0] = q[3]*t[0] + q[0]*t[3] + q[1]*t[2] - q[2]*t[1];
    vTargetVec[1] = q[3]*t[1] + q[1]*t[3] + q[2]*t[0] - q[0]*t[2];
    vTargetVec[2] = q[3]*t[2] + q[2]*t[3] + q[0]*t[1] - q[1]*t[0];
}

void main() {
    vec3 p = vec3(vaVertex);
    rotByAxisAngle(p, vec3(0.0, 0.0, 1.0), vcRotation);
    gl_Position = vec4(p, 1.0);
    maFragment = vaFragment;
}
