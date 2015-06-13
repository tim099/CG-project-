#ifndef POSITION_H_
#define POSITION_H_
#include <GL/glew.h>
#include <glm/glm.hpp>
class Position {
public:
	Position();
	Position(glm::vec3 pos,glm::vec3 r);
	virtual ~Position();
	glm::vec3 pos;
	glm::vec3 r;
};

#endif /* POSITION_H_ */
