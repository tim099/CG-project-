#include <class/buffer/frameBuffer/FrameBuffer.h>
#include "class/texture/texture2D/Texture2D.h"
FrameBuffer::FrameBuffer(int _width,int _height) {
	width=_width;height=_height;
	FBOID=GenFramebuffer(width,height);
}
FrameBuffer::~FrameBuffer() {
	glDeleteFramebuffers(1,&FBOID);
	for(unsigned i=0;i<color_textures.size();i++){
		delete color_textures.at(i);
	}
	for(unsigned i=0;i<depth_textures.size();i++){
		delete depth_textures.at(i);
	}
}
float FrameBuffer::aspect()const{
	return ((float)width/(float)height);
}
void FrameBuffer::bind_buffer(){
	glBindFramebuffer(GL_FRAMEBUFFER,FBOID);//bind the SFBO
	glViewport(0,0,width,height);
	if(!color_textures.empty()){
		GLuint*DBcolor=new GLuint(color_textures.size());
		for(unsigned i=0;i<color_textures.size();i++)DBcolor[i]=(GL_COLOR_ATTACHMENT0+i);
		glDrawBuffers(color_textures.size(),DBcolor);
		delete[] DBcolor;
	}else{
		glDrawBuffer(GL_NONE);
	}
}
void FrameBuffer::unbind_buffer(int _width,int _height){
	glBindFramebuffer(GL_FRAMEBUFFER,0);//unbind the FBO
	glViewport(0,0,_width,_height);
}
Texture* FrameBuffer::push_color_texture(Texture* tex){
	glFramebufferTexture(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0+color_textures.size(),tex->TexID,0);
	color_textures.push_back(tex);
	return tex;
}
Texture* FrameBuffer::gen_color_texture(const void *pixels,GLint internalformat,GLenum format
		,GLenum type,int Parameteri){
	Texture* tex=Texture::gen_texture2D(pixels,width,height,internalformat,format,type,Parameteri);
	glFramebufferTexture(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0+color_textures.size(),tex->TexID,0);
	color_textures.push_back(tex);
	return tex;
}
Texture* FrameBuffer::push_depth_texture(Texture* tex){
	glFramebufferTexture(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,tex->TexID,0);
	depth_textures.push_back(tex);
	depth_buffer=tex;
	return tex;
}
Texture* FrameBuffer::gen_depth_texture(GLint internalformat,GLenum format
		,GLenum type,int Parameteri){
	Texture* tex=Texture::gen_texture2D(0,width,height,internalformat,format,type,Parameteri);
	glFramebufferTexture(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,tex->TexID,0);
	depth_textures.push_back(tex);
	depth_buffer=tex;
	return tex;
}
void FrameBuffer::bind_depth_texture(int i){
	bind_buffer();
	Texture* tex=depth_textures.at(i);
	depth_buffer=tex;
	glFramebufferTexture(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,tex->TexID,0);
}
GLuint FrameBuffer::GenFramebuffer(int width,int height){
	GLuint FBO;
	glGenFramebuffers(1,&FBO);
	glBindFramebuffer(GL_FRAMEBUFFER,FBO);//GL_FRAMEBUFFER
	/*
	glGenRenderbuffers(1,&depth_buffer);
	glBindRenderbuffer(GL_RENDERBUFFER,depth_buffer);
	glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH_COMPONENT,width,height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,GL_RENDERBUFFER,depth_buffer);
	 */
	/*GLuint err=glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (err!=GL_FRAMEBUFFER_COMPLETE){
		std::cout<<"There is a problem with the FBO:"<<FBO<<"err:"<<err<<std::endl;
	}*/
	return FBO;
}
