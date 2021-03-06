#ifndef PARALLELLIGHT_H_
#define PARALLELLIGHT_H_
#include <class/light/Light.h>
class ParallelLight : public Light{
public:
	ParallelLight(glm::vec3 vec,glm::vec3 color);
	virtual ~ParallelLight();
	glm::mat4 sent_uniform(GLuint programID,float aspect,double shadow_size,glm::vec3 trans);
	glm::mat4 get_LVP(float aspect,double size,glm::vec3 trans)const;
	glm::vec3 vec;
	glm::vec3 color;
protected:

};

#endif /* PARALLELLIGHT_H_ */
