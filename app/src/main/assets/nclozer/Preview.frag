#extension GL_OES_EGL_image_external : require
precision mediump float;
varying vec2 maFragment;

uniform samplerExternalOES vTextureUnit;

void main() {
    gl_FragColor = texture2D(vTextureUnit, maFragment);
}
