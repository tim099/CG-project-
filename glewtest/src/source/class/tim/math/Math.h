#ifndef MATH_H_
#define MATH_H_
#include <glm/glm.hpp>
namespace Tim {

class Math {
public:
	Math();
	virtual ~Math();
	static float max(glm::vec3 v);
	static int get_val_at(int val,int at);
	static int get_len(int val);
	static glm::mat4 BiasMat();
};

} /* namespace Tim */

#endif /* MATH_H_ */
