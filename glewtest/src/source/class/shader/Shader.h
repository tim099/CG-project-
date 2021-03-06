#ifndef SHADER_H_
#define SHADER_H_
#include <string>
#include <GL/glew.h>
class Shader {
public:
	Shader();
	virtual ~Shader();
	void LoadShader(const char* vertex_path,const char* fragment_path);
	void LoadShader(const char* vertex,const char* geometry,const char* fragment);
	void active_shader();
	void EnableNormapping();
	void DisableNormapping();
	void sent_Uniform1i(const char* name,int i);
	GLuint programID;
protected:
	static GLuint creat_shader(const char* src,GLenum type);
	static void read_shader(std::string &ShaderCode,const char* path);//
	static void check_shader(GLuint VertexShaderID,GLint &Result,int &InfoLogLength);
	static void check_program(GLuint ProgramID,int &InfoLogLength);
	static void compile_shader(GLuint ShaderID,std::string &ShaderCode);

};

#endif /* SHADER_H_ */
