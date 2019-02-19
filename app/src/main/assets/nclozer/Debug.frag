precision mediump float;
varying vec2 maFragment;

uniform sampler2D vDebugTextureUnit;

void main(void)
{
    gl_FragColor = texture2D(vDebugTextureUnit, maFragment);
}
