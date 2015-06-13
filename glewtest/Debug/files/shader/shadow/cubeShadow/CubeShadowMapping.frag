#version 400 core

layout(location=0)out float depth;
in vec4 pos;

void main(){ 
 	depth=pos.z/pos.w;   
}