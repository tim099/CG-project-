#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <class/texture/Image.h>
#include <vector>
const int TEXTURE_BMP=1;

const int P_NONE=0;
const int P_MipMap=1;
const int P_Linear=2;
const int P_Nearest=3;
class Texture2D;
class Texture {
public:
	Texture(GLuint TexID,GLenum target,GLenum format);
	virtual ~Texture();
	virtual Texture2D* Tex2D();


	static void usetextureVec(GLuint programID,std::vector<Texture*>& texvec,int num,const char *name);
	static Texture2D* gen_texture2D(const void *pixels,GLsizei width,GLsizei height,GLint internalformat,GLenum format
			,GLenum type=GL_UNSIGNED_BYTE,int Parameteri=P_MipMap);
	static Texture2D* gen_texture2D(Image* image,GLint internalformat,
			GLenum type=GL_UNSIGNED_BYTE,int Parameteri=P_MipMap);
	static void draw_texture(Texture* tex,GLuint shader2D,double winaspect=1.0,double texaspect=1.0,GLfloat alpha=1.0,
			glm::vec3 pos=glm::vec3(0,0,0),double size=1.0);

	virtual void sent_uniform(GLuint programID,int num,const char *name)const=0;
	GLuint TexID;
	GLenum target;
	GLenum format;
protected:
	static GLuint gen_texture_vertex(GLfloat width,GLfloat height,glm::vec3 pos=glm::vec3(0,0,0));
};

#endif /* TEXTURE_H_ */
