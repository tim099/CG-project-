#include "class/texture/texture2D/Texture2D.h"
#include "class/texture/Image.h"
#include <iostream>
Texture2D::Texture2D(GLuint _TexID,glm::ivec2 _size,GLenum _type,GLenum _format)
: Texture(_TexID,GL_TEXTURE_2D,_type,_format){
	size=_size;
}
Texture2D::~Texture2D() {

}
Texture2D* Texture2D::Tex2D(){
	return this;
}
Texture2D* Texture2D::loadBMP_to_sobel(const char * imagepath,int Parameteri){
	Image* bmp=new Image();
	bmp->loadBMP(imagepath);
	Image::convert_to_sobel(bmp);
	Texture2D* texture=gen_texture2D(bmp,GL_RGB,GL_UNSIGNED_BYTE,Parameteri);//BMP is BGR Format
	return texture;
}
Texture2D* Texture2D::loadBMP(const char * imagepath,int Parameteri){
	Image* bmp_img=new Image();
	bmp_img->loadBMP(imagepath);
	Texture2D* texture=gen_texture2D(bmp_img,GL_RGB,GL_UNSIGNED_BYTE,Parameteri);//BMP is BGR Format
	delete bmp_img;
	return texture;
}
void Texture2D::sent_uniform(GLuint programID,int num,const char *name)const{
	glUniform1i(glGetUniformLocation(programID,name),num);//texturebuffer
	glActiveTexture(GL_TEXTURE0+num);
	glBindTexture(target,TexID);//GL_TEXTURE_CUBE_MAP
}
Image* Texture2D::convert_to_image(GLenum _format){
	glBindTexture(GL_TEXTURE_2D,TexID);
	Image *img=new Image(size,_format);
	glGetTexImage(GL_TEXTURE_2D,0,_format,type,img->data);
	return img;
}
