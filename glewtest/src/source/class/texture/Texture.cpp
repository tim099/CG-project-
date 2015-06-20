#include "class/texture/texture.h"
#include "class/tim/string/String.h"
#include "class/texture/texture2D/Texture2D.h"
#include "class/buffer/Buffer.h"
#include "class/model/Vertex.h"
#include "class/shader/shader2D/Shader2D.h"
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <GL/glfw3.h>
Texture::Texture(GLuint _TexID,GLenum _target,GLenum _type,GLenum _format) {
	TexID=_TexID;
	target=_target;
	type=_type;
	format=_format;
}
Texture::~Texture() {
	glDeleteTextures(1,&TexID);
}
Texture2D* Texture::Tex2D(){
	return 0;
}
void Texture::usetextureVec(GLuint programID,std::vector<Texture*>& texvec,int num,const char *name){
	int slen=strlen(name);
	char temp[100];
	for(int i=0;i<slen;i++){
		temp[i]=name[i];
	}
	for(unsigned i=0;i<texvec.size();i++){
		Tim::String::gen_array_num(temp+slen,i);
		texvec.at(i)->sent_uniform(programID,i+num,temp);
	}
}
GLuint Texture::gen_texture_vertex(GLfloat width,GLfloat height,glm::vec3 pos){
	GLfloat vertex_buffer_data[18];
	Vertex::gen_quad_vt(vertex_buffer_data,pos,glm::vec3(width,height,0),true);
	return Buffer::gen_buffer(vertex_buffer_data,sizeof(vertex_buffer_data));
}
void Texture::draw_texture(Shader2D* shader2D,double winaspect,double texaspect,GLfloat alpha,glm::vec3 pos
		,double size){
	std::cerr<<"error not implement draw texture in this class"<<std::endl;
}
