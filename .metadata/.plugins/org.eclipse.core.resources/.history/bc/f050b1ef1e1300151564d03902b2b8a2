#ifndef MOUSE_H_
#define MOUSE_H_
#include <GL/glew.h>
#include <GL/glfw3.h>
#include <glm/glm.hpp>
class Mouse {
public:
	Mouse();
	virtual ~Mouse();

	void cursor_pos_callback(GLFWwindow* window, double x, double y);
	void scroll_callback(GLFWwindow* window,double xoffset,double yoffset);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void tic();
	glm::ivec2 pos_delta()const;

	glm::ivec2 pos;
	glm::ivec2 prev_pos;
	double scroll;
	bool left,right,mid;
protected:

};

#endif /* MOUSE_H_ */
