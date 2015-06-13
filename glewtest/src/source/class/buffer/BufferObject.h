#ifndef BUFFEROBJECT_H_
#define BUFFEROBJECT_H_
#include <GL/glew.h>
#include <glm/glm.hpp>
class Model;
class BufferObject {
public:
	BufferObject(GLuint vtbuffer,GLuint uvbuffer,GLuint texturebuffer,GLuint nbuffer,int vertex_num
			,glm::vec4 mat);
	BufferObject(Model *m);
	virtual ~BufferObject();
	void bind_buffer(GLuint programID);
	void draw(GLuint programID);

	int vertex_num;
	GLuint vtbuffer;
	GLuint uvbuffer;
	GLuint vnbuffer;
	glm::vec4 mat;
private:

};

#endif /* BUFFEROBJECT_H_ */
