#ifndef IMAGE_H_
#define IMAGE_H_
#include <GL/glew.h>
#include <glm/glm.hpp>
class Image {
public:
	Image();
	Image(glm::ivec2 size,GLenum format=GL_RGB);
	virtual ~Image();
	static void convert_to_sobel(Image* image,glm::vec2 dv=glm::vec2(2,1));


	void initialize(glm::ivec2 size,GLenum format);
	void loadBMP(const char * imagepath);
	GLenum format;
	glm::ivec2 size;
	unsigned int imageSize;   // = width*height*3
	unsigned char * data;// Actual RGB data
protected:
	int data_size;
};

#endif /* IMAGE_H_ */
