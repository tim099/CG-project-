#ifndef WINDOW_H_
#define WINDOW_H_
class GLFWwindow;
#include <glm/glm.hpp>
class Window {
	static bool glewinitial;
	static bool glfwinitial;
public:
	Window();
	Window(glm::ivec2 size,const char* name,bool full_screen);
	virtual ~Window();

	void creat_window(glm::i16vec2 size,const char* name,bool full_screen);
	float aspect()const;
	glm::ivec2 get_size()const;
	GLFWwindow* get_window()const;

protected:
	void glewinit();
	void glfwinit();
	GLFWwindow* window;
	glm::ivec2 size;

};


#endif /* WINDOW_H_ */
