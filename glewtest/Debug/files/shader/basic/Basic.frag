#version 400 core
#define MAX_LIGHT 100 

in VertexData {
    vec2 UV;
    vec3 Normal;
    vec3 position;
}vert;

layout(location = 0)out vec4 color;

uniform sampler2D myTextureSampler;

uniform vec3 camera_pos;

uniform int parallellight_num;
uniform vec3 parallellight_vec[MAX_LIGHT];
uniform vec3 parallellight_color[MAX_LIGHT];

uniform int pointlight_num;
uniform vec3 pointlight_pos[MAX_LIGHT];
uniform vec3 pointlight_color[MAX_LIGHT];
uniform vec4 mat;

float specular_value(float specular_val){
	return mat.y*pow(specular_val,100*mat.y);//mat.w
}
vec3 light(vec3 N){
	vec3 total_light=vec3(0,0,0);
    vec3 light_v;
    vec3 reflect_v;
    vec3 pos_cam_v=normalize(vert.position-camera_pos);
    float light_dis;
    float light_val;
    float specular_val;
    for(int i=0;i<pointlight_num;i++){
    	//diffuse
        light_v=pointlight_pos[i]-vert.position;
    	light_dis=length(light_v);
    	light_val=mat.x*dot(N,normalize(light_v));
    	//specular
		reflect_v=light_v-(2*dot(N,light_v))*N;		
		specular_val=dot(pos_cam_v,normalize(reflect_v));
		if(specular_val>0.0f){
			light_val+=specular_value(specular_val);			
		}
		light_val/=(light_dis*light_dis);
		if(light_val<0.0)light_val=0.0;	
		total_light+=light_val*pointlight_color[i];
    }
    for(int i=0;i<parallellight_num;i++){
    	//diffuse
    	light_v=normalize(-parallellight_vec[i]);//reverse	
    	light_val=mat.x*dot(N,light_v);
    	//specular
    	reflect_v=light_v-(2*dot(N,light_v))*N;
    	specular_val=dot(pos_cam_v,normalize(reflect_v));
    	if(specular_val>0.0f){
			light_val+=specular_value(specular_val);			
		}
		if(light_val<0.0)light_val=0.0;	
    	total_light+=light_val*parallellight_color[i];  
    }
    return total_light;
}
void main(){ 
	vec3 tex_color=(texture(myTextureSampler,vert.UV).rgb);
    vec3 total_light=light(vert.Normal)+mat.w;

    color = vec4((total_light)*tex_color,1.0);
}