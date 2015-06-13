#include <class/window/Window.h>
#include <GL/glew.h>
#include <GL/glfw3.h>
Window::Window() {
	window=0;
	height=0,width=0;
}
Window::Window(int _width,int _height,const char* name,bool full_screen) {
	creat_window(_width,_height,name,full_screen);
	height=_height,width=_width;
}
Window::~Window() {

}
void Window::glewinit(){
	//if(glewinitial)return;
	//glewinitial=true;
    glewExperimental=true;
    glewInit();
}
void Window::glfwinit(){
	//if(glfwinitial)return;
	//glfwinitial=true;
	glfwInit();
}
float Window::aspect()const{
	return ((float)width/(float)height);
}
int Window::get_width()const{
	return width;
}
int Window::get_height()const{
	return height;
}
void Window::creat_window(int width,int height,const char* name,bool full_screen){
	glfwinit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    if(full_screen)window=glfwCreateWindow(width,height,name,glfwGetPrimaryMonitor(),NULL);//full screen
    else window=glfwCreateWindow(width,height,name,NULL,NULL);
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glewinit();
}
GLFWwindow* Window::get_window()const{
	return window;
}
