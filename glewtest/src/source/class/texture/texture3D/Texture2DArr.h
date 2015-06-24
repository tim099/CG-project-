#ifndef TEXTURE2DARR_H_
#define TEXTURE2DARR_H_
#include "class/texture/Texture.h"
class Image;
class Texture2DArr : public Texture {
public:
	Texture2DArr(GLuint TexID,glm::ivec3 size,GLenum type,GLenum format);
	virtual ~Texture2DArr();
	virtual void sent_uniform(Shader* shader,int num,const char *name)const;
	static Texture2DArr* gen_texture2DArr(Image *img,GLint internalformat,
			GLenum type=GL_UNSIGNED_BYTE,int Parameteri=P_MipMap);
	static Texture2DArr* gen_texture2DArr(const void *pixels,glm::ivec3 size,GLint internalformat,GLenum format,
			GLenum type=GL_UNSIGNED_BYTE,GLsizei mipLevelCount=1,int Parameteri=P_MipMap);
	virtual void draw_texture(Shader2D* shader2D,double winaspect=1.0,double texaspect=1.0,GLfloat alpha=1.0,
			glm::vec3 pos=glm::vec3(0,0,0),double size=1.0);
	glm::ivec3 size;
};

#endif /* TEXTURE2DARR_H_ */
