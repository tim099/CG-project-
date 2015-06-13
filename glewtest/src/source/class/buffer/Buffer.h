#ifndef BUFFER_H_
#define BUFFER_H_
#include <GL/glew.h>
class Buffer {
public:
	Buffer();
	virtual ~Buffer();
	static GLuint gen_buffer(GLfloat* data,int size);
	static GLuint GenVertexArray();
	//static void Draw_Framebuffer();
	static void bind_vtbuffer(GLuint vertexbuffer);
	static void bind_uvbuffer(GLuint uvbuffer);
	static void bind_vnbuffer(GLuint vnbuffer);
	static void disable_all_buffer();
protected:

};

#endif /* BUFFER_H_ */
