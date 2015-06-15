#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_
#include <vector>
#include "class/buffer/Buffer.h"
#include "class/texture/Texture.h"
class FrameBuffer {
public:
	FrameBuffer(glm::ivec2 size);
	virtual ~FrameBuffer();

	static void unbind_buffer(glm::ivec2 size);
	void bind_buffer();
	void bind_depth_texture(int i);
	void ReadPixels(glm::ivec2 pos,glm::ivec2 size,GLenum format,GLenum type,GLvoid * data);
	float aspect()const;

	GLuint GenFramebuffer(glm::ivec2 size);
	Texture* gen_color_texture(const void *pixels,GLint internalformat,GLenum format
			,GLenum type=GL_UNSIGNED_BYTE,int Parameteri=P_MipMap);
	Texture* gen_depth_texture(GLint internalformat,GLenum format
			,GLenum type=GL_UNSIGNED_BYTE,int Parameteri=P_MipMap);
	Texture* push_depth_texture(Texture* tex);
	Texture* push_color_texture(Texture* tex);
	glm::ivec2 size;
	Texture* depth_buffer;
	GLuint FBOID;
	std::vector<Texture*>color_textures;
	std::vector<Texture*>depth_textures;
};

#endif /* FRAMEBUFFER_H_ */
