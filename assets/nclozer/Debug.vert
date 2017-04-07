precision highp float;
precision highp int;
varying vec2 maFragment;

attribute vec3 vaDebugVertex;
attribute vec2 vaDebugFragment;
uniform vec3 vaDebugPosition;
uniform vec2 vaDebugBox;

vec4 getDebugPosition()
{
    return vec4(
        (vaDebugPosition[1]*8.125 + vaDebugPosition[0] + vaDebugVertex.x)*32.0/vaDebugBox.x - 1.0,
        (3.0 - vaDebugPosition[2] + vaDebugVertex.y)*40.0/vaDebugBox.y - 1.0,
        -vaDebugVertex.z,
        1.0
    );
}

float getDebugValue(vec4 v0, vec4 v1, vec4 v2, vec4 v3)
{
    vec4 v = v0;

    if (vaDebugPosition[1] == 1.0) {
        v = v1;
    }
    if (vaDebugPosition[1] == 2.0) {
        v = v2;
    }
    if (vaDebugPosition[1] == 3.0) {
        v = v3;
    }
    return v[int(vaDebugPosition[2])];
}

vec2 getDebugFragment(vec4 v0, vec4 v1, vec4 v2, vec4 v3)
{
    float value = getDebugValue(v0, v1, v2, v3);
    float index = vaDebugPosition[0];
    float shift = 0.0;
    float num = 11.0;

    if (value < 0.0) {
        value = -value;
        num = 12.0;
    }
    while (value >= 1.0) {
        value = value/10.0;
        shift = shift + 1.0;
    }
    if (index == shift + 1.0) {
        num = 10.0;
        index = 0.0;
    }
    if (index > shift + 1.0) {
        index = index - 1.0;
    }
    while (index > 0.0) {
        num = float(int(value*10.0));
        value = value*10.0 - num;
        index = index - 1.0;
    }
    return vec2(
        (num + vaDebugFragment.x)/13.0,
        vaDebugFragment.y
    );
}

void setDebugOutput(vec4 v0, vec4 v1, vec4 v2, vec4 v3)
{
    gl_Position = getDebugPosition();
    maFragment = getDebugFragment(v0, v1, v2, v3);
}

// BEGIN debug
uniform vec3 vaFPS;

void main() {
    gl_Position = vec4(vaFPS.x, vaFPS.y, vaFPS.z, 0.0);

    // APPLY debug
    setDebugOutput(gl_Position, gl_Position, gl_Position, gl_Position);
}
