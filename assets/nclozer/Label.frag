precision mediump float;
varying vec2 maFragment;

uniform sampler2D vTextureUnit;
uniform vec4 vaLabelColor;

void main(void)
{
    gl_FragColor = vec4(vaLabelColor.r, vaLabelColor.g, vaLabelColor.b, vaLabelColor.a*texture2D(vTextureUnit, maFragment).a);
}
