#version 400 core
#extension GL_EXT_texture_array : enable

in vec2 UV;
flat in int index;  

layout(location = 0)out vec4 color;

uniform sampler2DArray myTextureArrSampler;
uniform float alpha;

void main(){ 
	//vec3 temp_color=texture2DArray(myTextureArrSampler,vec3(UV,index)).rgb;
	//vec3 temp_color=texture2DArray(myTextureArrSampler,vec3(UV,0)).rgb;
	vec3 tex_color=texture(myTextureArrSampler,vec3(UV,0)).rgb;
	vec3 temp_color=vec3(0.7,0,0)+tex_color;
    color=vec4(temp_color,alpha);
}