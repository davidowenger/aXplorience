precision mediump float;
uniform vec4 mModel;
uniform vec4 mProjection;
attribute vec4 maVertexPOI;
varying vec4 vColor;
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
    vec4 t = vec4(maVertexPOI.x, maVertexPOI.y, maVertexPOI.z - mModel.z, 1.0);
    gl_Position = vec4(mProjection.x*(mModel.x/t.z + t.x/(1.0 + log(t.z))), mProjection.y*(mModel.y/t.z + t.y/(1.0 + log(t.z))), -1.0 + 2.0*(t.z - mProjection.z)/(mProjection.w - mProjection.z), 1.0);
    vColor = vec4(maVertexPOI.w, 0.0, maVertexPOI.w, 1.0);
}
