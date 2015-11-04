#extension GL_OES_EGL_image_external : require

precision mediump float;
uniform samplerExternalOES mcSamplerPreview;
varying vec2 mCoordPreviewFU;

void main() {
    gl_FragColor = texture2D(mcSamplerPreview, vec2(mCoordPreviewFU.x, mCoordPreviewFU.y));
}
