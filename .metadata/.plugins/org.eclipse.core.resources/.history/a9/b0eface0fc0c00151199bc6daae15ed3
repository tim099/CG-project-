#version 400 core

layout(location = 0)in vec3 vertexPosition;

out vec4 position;

uniform mat4 M; 

void main(){ 
	position=M*vec4(vertexPosition,1);//real world pos
    gl_Position=position;
}