#ifndef TEXTURE2D_H_
#define TEXTURE2D_H_
#include "class/texture/texture.h"
class Image;
class Texture2D : public Texture {
public:
	Texture2D(GLuint TexID,int width,int height,GLenum format);
	virtual ~Texture2D();
	static Texture2D* loadBMP(const char * imagepath,int Parameteri=P_MipMap);
	static Texture2D* loadBMP_to_sobel(const char * imagepath,int Parameteri=P_MipMap);
	virtual Texture2D* Tex2D();
	virtual void sent_uniform(GLuint programID,int num,const char *name)const;
	Image* convert_to_image(GLenum format=GL_RGB);
	int width,height;
protected:

};

#endif /* TEXTURE2D_H_ */
