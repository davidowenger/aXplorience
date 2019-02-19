precision mediump float;
varying vec2 maFragment;

void main() {
    gl_FragColor = vec4(0.71*maFragment.x, 0.71, maFragment.y, 0.2*maFragment.x + maFragment.y);;
}
