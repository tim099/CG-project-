#ifndef UNIFORM_H_
#define UNIFORM_H_
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <string>
class Uniform {
public:
	Uniform();
	virtual ~Uniform();
	static void sentMat4Arr(GLuint programID,glm::mat4* MatArr,int num,std::string name);
};

#endif /* UNIFORM_H_ */
