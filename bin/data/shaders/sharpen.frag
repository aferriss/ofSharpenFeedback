uniform sampler2DRect src_tex_unit0;

float kernel[9];
vec2 offset[9];

float step_w = 0.01;
float step_h = 0.01;

void main() {
    
    
    offset[0] = vec2(-step_w, -step_h);
    offset[1] = vec2(0.0, -step_h);
    offset[2] = vec2(step_w, -step_h);
    offset[3] = vec2(-step_w, 0.0);
    offset[4] = vec2(0.0, 0.0);
    offset[5] = vec2(step_w, 0.0);
    offset[6] = vec2(-step_w, step_h);
    offset[7] = vec2(0.0, step_h);
    offset[8] = vec2(step_w, step_h);
    
    
    kernel[0] = -1.; kernel[1] = -1.; kernel[2] = -1.;
    kernel[3] = -1.; kernel[4] = 9.; kernel[5] = -1.;
    kernel[6] = -1.; kernel[7] = -1.; kernel[8] = -1.;
    
    vec4 sum = vec4(0.0);
    int i;
    
    for (i = 0; i < 9; i++) {
        vec4 color = texture2DRect(src_tex_unit0, gl_TexCoord[0].st + offset[i]);
        sum += color * kernel[i];
    }
    
    
    gl_FragColor = sum + vec4(0.01,0.01,0.01,0.0) ;
}