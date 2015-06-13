#ifndef WINDOW_H_
#define WINDOW_H_
class GLFWwindow;

class Window {
	//static bool glewinitial;
	//static bool glfwinitial;
public:
	Window();
	Window(int width,int height,const char* name,bool full_screen);
	virtual ~Window();

	void creat_window(int width,int height,const char* name,bool full_screen);
	float aspect()const;
	int get_width()const;
	int get_height()const;
	GLFWwindow* get_window()const;

protected:
	void glewinit();
	void glfwinit();
	GLFWwindow* window;
	int height,width;

};
//bool Window::glewinitial=false;
//bool Window::glfwinitial=false;

#endif /* WINDOW_H_ */
