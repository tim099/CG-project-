#include "class/tim/math/Position.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
Position::Position() {
	initialize(glm::vec3(),glm::vec3());
}
Position::Position(glm::vec3 _pos,glm::vec3 _r) {
	initialize(_pos,_r);
}
Position::~Position() {

}
void Position::initialize(glm::vec3 _pos,glm::vec3 _r){
	pos=_pos;
	r=_r;
	parent_pos=0;
}
glm::mat4 Position::PosMat()const{
	glm::mat4 M=glm::mat4(1.0f);
	M*=glm::translate(pos);
	if(r.y!=0.0){
	    glm::mat4 rmat=glm::rotate(r.y,glm::vec3(0,1,0));
	    M*=rmat;
	}
	return M;
}
