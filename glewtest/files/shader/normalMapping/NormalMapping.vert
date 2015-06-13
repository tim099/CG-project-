#version 400 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal;

out vec2 UV;
out vec3 Normal;
out vec4 position;
out vec4 MVP_pos;

uniform mat4 VP;
uniform mat4 M; 

void main(){ 

	position=M*vec4(vertexPosition,1);//real world pos
	MVP_pos=VP*position; 
    gl_Position=MVP_pos;   
 	Normal=(M*vec4(vertexNormal,0)).xyz;
    UV = vertexUV;

}