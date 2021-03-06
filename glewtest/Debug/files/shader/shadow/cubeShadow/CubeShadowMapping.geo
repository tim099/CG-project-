#version 400 core


layout (triangles)in;

layout(triangle_strip,max_vertices=18)out;
out vec4 pos;

out int gl_Layer;
uniform mat4 LVP[6];


void main(){
	for(int n=0;n<6;n++){//6 faces
		for(int i=0;i<3;i++){
			gl_Position=(LVP[n]*gl_in[i].gl_Position);
			pos=gl_Position;
			gl_Layer=n;
			EmitVertex();
		}
		EndPrimitive();
	}
}  