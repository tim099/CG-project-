#ifndef IMAGE_H_
#define IMAGE_H_
#include <GL/glew.h>
#include <glm/glm.hpp>
class Image {
public:
	Image();
	Image(unsigned int width,unsigned int height,GLenum format=GL_RGB);
	virtual ~Image();
	static void convert_to_sobel(Image* image,glm::vec2 dv=glm::vec2(2,1));


	void initialize(unsigned int width,unsigned int height,GLenum format);
	void loadBMP(const char * imagepath);
	GLenum format;
	unsigned int width,height;
	unsigned int imageSize;   // = width*height*3
	unsigned char * data;// Actual RGB data
protected:

};

#endif /* IMAGE_H_ */
