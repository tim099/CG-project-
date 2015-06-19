#version 400 core

layout(triangles)in;
layout(triangle_strip,max_vertices=3)out;

in VertexData {
	vec2 UV;
	vec3 Normal;
	vec4 position;
	vec4 MVP_pos;
	vec3 T;
	vec3 B;
}vertout[3];

out VertexData{
	vec2 UV;
	vec3 Normal;
	vec4 position;
	vec4 MVP_pos;
	vec3 T;
	vec3 B;
}vert;
void main(){
	for(int i=0;i<3;i++){
		gl_Position=gl_in[i].gl_Position;
		vert.UV=vertout[i].UV;
		vert.Normal=vertout[i].Normal;
		vert.position=vertout[i].position;
		vert.MVP_pos=vertout[i].MVP_pos;
		vert.T=vertout[i].T;//error
		vert.B=vertout[i].B;
		EmitVertex();
	}
	EndPrimitive();
} 