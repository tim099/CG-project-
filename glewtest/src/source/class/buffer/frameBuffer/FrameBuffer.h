#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_
#include <vector>
#include <class/buffer/Buffer.h>
#include <class/texture/texture.h>
class FrameBuffer {
public:
	FrameBuffer(int width,int height);
	virtual ~FrameBuffer();

	static void unbind_buffer(int width,int height);
	void bind_buffer();
	void bind_depth_texture(int i);
	float aspect()const;

	GLuint GenFramebuffer(int width,int height);
	Texture* gen_color_texture(const void *pixels,GLint internalformat,GLenum format
			,GLenum type=GL_UNSIGNED_BYTE,int Parameteri=P_MipMap);

	Texture* gen_depth_texture(GLint internalformat,GLenum format
			,GLenum type=GL_UNSIGNED_BYTE,int Parameteri=P_MipMap);
	Texture* push_depth_texture(Texture* tex);
	Texture* push_color_texture(Texture* tex);
	int width, height;
	Texture* depth_buffer;
	GLuint FBOID;
	std::vector<Texture*>color_textures;
	std::vector<Texture*>depth_textures;
};

#endif /* FRAMEBUFFER_H_ */
