#version 400 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal;

uniform mat4 VP;
uniform mat4 M; 

out VertexData {
	vec2 UV;
	vec3 Normal;
	vec4 position;
	vec4 MVP_pos;
	vec3 T;
	vec3 B;
}vertout;

void main(){ 	
	vertout.position=M*vec4(vertexPosition,1);//real world pos
	vertout.MVP_pos=VP*vertout.position; 
    gl_Position=vertout.MVP_pos;   
 	vertout.Normal=(M*vec4(vertexNormal,0)).xyz;
    vertout.UV = vertexUV;
    
    if(vertout.Normal!=vec3(0.3,0.3,0.3))vertout.T=normalize(cross(vertout.Normal,vec3(0.3,0.3,0.3)));
	else vertout.T=normalize(cross(vertout.Normal,vec3(0.31,0.29,0.31)));
	vertout.B=normalize(cross(vertout.Normal,vertout.T));

}