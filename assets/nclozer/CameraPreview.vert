precision mediump float;
uniform float mcTransformation;
attribute vec4 mVertexPreview;
attribute vec2 mCoordPreview;
varying vec2 mCoordPreviewFU;
const float mcPi = 3.142;

vec4 mult(vec4 q1, vec4 q2)
{
    return vec4(
        q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y,
        q1.w*q2.y + q1.y*q2.w + q1.z*q2.x - q1.x*q2.z,
        q1.w*q2.z + q1.z*q2.w + q1.x*q2.y - q1.y*q2.x,
        q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z
    );
}

void conj(inout vec4 q)
{
    q.x = -q.x;
    q.y = -q.y;
    q.z = -q.z;
}

void inv(inout vec4 q)
{
    float norm2 = dot(q,q);
    q.x = -q.x/norm2;
    q.y = -q.y/norm2;
    q.z = -q.z/norm2;
    q.w =  q.w/norm2;
}

void rot(inout vec4 v, vec4 q)
{
    vec4 t = mult(q, v);
    conj(q);
    v = mult(t, q);
}

void unit(inout vec4 v)
{
    float norm = length(v);

    if (norm > 0.00) {
       v.x /= norm;
       v.y /= norm;
       v.z /= norm;
       v.w /= norm;
    }
}

void rotByAngle(inout vec4 v, float angle, vec4 axe)
{
    float angled2 = angle/2.00;
    float sinangled2 = sin(angled2);
    axe.x *= sinangled2;
    axe.y *= sinangled2;
    axe.z *= sinangled2;
    axe.w = cos(angled2);
    rot(v, axe);
}

void main() {
    mCoordPreviewFU = mCoordPreview;
    vec4 t = mVertexPreview;
    rotByAngle(t, mcTransformation*mcPi/2.0, vec4(0.0, 0.0, 1.0, 0.0));
    gl_Position = t;
}
