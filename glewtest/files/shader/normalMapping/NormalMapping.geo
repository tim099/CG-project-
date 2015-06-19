#version 400 core

layout(triangles)in;
layout(triangle_strip,max_vertices=3)out;

in VertexDataOut {
	vec2 UV;
	vec3 Normal;
	vec3 vertexPosition;
	vec4 position;
	vec4 MVP_pos;
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
    vec3 dPos1=vertout[1].vertexPosition-vertout[0].vertexPosition;
    vec3 dPos2=vertout[2].vertexPosition-vertout[0].vertexPosition;
 	vec2 dUV1=vertout[1].UV-vertout[0].UV;
    vec2 dUV2=vertout[2].UV-vertout[0].UV;
	float r =1.0f/(dUV1.x*dUV2.y-dUV1.y*dUV2.x);
	vec3 T=(dPos1*dUV2.y-dPos2*dUV1.y)*r;
	vec3 B=(dPos2*dUV1.x-dPos1*dUV2.x)*r;

	for(int i=0;i<3;i++){
		gl_Position=gl_in[i].gl_Position;
		vert.UV=vertout[i].UV;
		vert.Normal=vertout[i].Normal;
		vert.position=vertout[i].position;
		vert.MVP_pos=vertout[i].MVP_pos;
		vert.T=T;
		vert.B=B;
		EmitVertex();
	}
	EndPrimitive();
} 