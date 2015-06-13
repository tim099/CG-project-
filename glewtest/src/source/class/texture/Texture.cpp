#include "class/tim/string/String.h"
#include "class/texture/texture.h"
#include "class/texture/texture2D/Texture2D.h"
#include "class/buffer/Buffer.h"
#include "class/model/Vertex.h"
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <GL/glfw3.h>
Texture::Texture(GLuint _TexID,GLenum _target,GLenum _format) {
	TexID=_TexID;
	target=_target;
	format=_format;
}
Texture::~Texture() {
	glDeleteTextures(1,&TexID);
}
Texture2D* Texture::Tex2D(){
	return 0;
}
Texture2D* Texture::gen_texture2D(Image* image,GLint internalformat,GLenum type,int Parameteri){
	return gen_texture2D(image->data,image->width,image->height,internalformat,image->format,type,Parameteri);
}
Texture2D* Texture::gen_texture2D(const void *pixels,GLsizei width,GLsizei height,GLint internalformat,GLenum format,GLenum type,int Parameteri){
	GLuint textureID;
	glGenTextures(1,&textureID);
	glBindTexture(GL_TEXTURE_2D,textureID);
	glTexImage2D(GL_TEXTURE_2D,0,internalformat,width,height,0,format,type,pixels);
	switch(Parameteri){
		case P_NONE:
			break;
		case P_MipMap:
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
			glGenerateMipmap(GL_TEXTURE_2D);
			break;
		case P_Linear:
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);//GL_NEAREST
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);//GL_NEAREST
			break;
		case P_Nearest:
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
			break;
		default:
			std::cout<<"err unknow texture Parameteri type:"<<Parameteri<<std::endl;

	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);//GL_CLAMP
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	Texture2D *tex=new Texture2D(textureID,width,height,internalformat);
	return tex;
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
	Vertex::gen_quad_vt(vertex_buffer_data,pos,glm::vec3(width,height,0));
	return Buffer::gen_buffer(vertex_buffer_data,sizeof(vertex_buffer_data));
}
void Texture::draw_texture(Texture* tex,GLuint shader2D,double winaspect,double texaspect,GLfloat alpha,glm::vec3 pos
		,double size){
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);

    GLuint tex_vertex=0;
	if(winaspect==texaspect){
		tex_vertex=gen_texture_vertex(1.0,1.0);
	}else{
		float height=1.0;
		double aspect=winaspect/texaspect;
		if(aspect>1.0)height=1.0/aspect;
		tex_vertex=gen_texture_vertex(height,height*aspect);
	}
	Buffer::bind_vtbuffer(tex_vertex);
	tex->sent_uniform(shader2D,0,"myTextureSampler");

	glUniform3f(glGetUniformLocation(shader2D,"position"),pos.x,pos.y,pos.z);
	glUniform1f(glGetUniformLocation(shader2D,"size"),size);
	glUniform1f(glGetUniformLocation(shader2D,"alpha"),alpha);
	glDrawArrays(GL_TRIANGLES,0,2*3);
    glDeleteBuffers(1,&tex_vertex);
    glDisableVertexAttribArray(0);//vertexbuffer
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
}
