#ifndef TEXTURE2D_H_
#define TEXTURE2D_H_
#include "class/texture/texture.h"
class Image;
class Texture2D : public Texture {
public:
	Texture2D(GLuint TexID,glm::ivec2 size,GLenum type,GLenum format);
	virtual ~Texture2D();
	static Texture2D* loadBMP(const char * imagepath,int Parameteri=P_MipMap);
	static Texture2D* loadBMP_to_sobel(const char * imagepath,int Parameteri=P_MipMap);
	static Texture2D* gen_texture2D(const void *pixels,glm::ivec2 size,GLint internalformat,GLenum format
			,GLenum type=GL_UNSIGNED_BYTE,int Parameteri=P_MipMap);
	static Texture2D* gen_texture2D(Image* image,GLint internalformat,
			GLenum type=GL_UNSIGNED_BYTE,int Parameteri=P_MipMap);
	virtual Texture2D* Tex2D();
	virtual void sent_uniform(GLuint programID,int num,const char *name)const;
	virtual void draw_texture(Shader2D* shader2D,double winaspect=1.0,double texaspect=1.0,GLfloat alpha=1.0,
			glm::vec3 pos=glm::vec3(0,0,0),double size=1.0);
	Image* convert_to_image(GLenum format=GL_RGB);
	glm::ivec2 size;
protected:

};

#endif /* TEXTURE2D_H_ */
