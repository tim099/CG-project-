#ifndef CALLBACKFUNC_H_
#define CALLBACKFUNC_H_
#include <GL/glew.h>
#include <GL/glfw3.h>
#include "class/input/keyboard/keyboard.h"
#include <class/input/mouse/Mouse.h>
//static GLFWwindow *window;
extern KeyBoard *keyboard;
extern Mouse *mouse;

void keyboard_callback(GLFWwindow *window,int key,int scancode,int action,int mods);
void cursor_pos_callback(GLFWwindow* window, double x, double y);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void callback_rigister(GLFWwindow *_window,KeyBoard *_keyboard,Mouse *_mouse);

void keyboard_callback(GLFWwindow *window,int key,int scancode,int action,int mods){
	keyboard->inputkey(window,key,scancode,action,mods);
}
void cursor_pos_callback(GLFWwindow* window, double x, double y){
	mouse->cursor_pos_callback(window,x,y);
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
	mouse->scroll_callback(window,xoffset,yoffset);
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
	mouse->mouse_button_callback(window,button,action,mods);
}
void callback_rigister(GLFWwindow *window,KeyBoard *_keyboard,Mouse *_mouse){
	keyboard=_keyboard;
	mouse=_mouse;
	//window=_window;
	glfwSetKeyCallback(window,keyboard_callback);
	glfwSetCursorPosCallback(window,cursor_pos_callback);
	glfwSetScrollCallback(window,scroll_callback);
	glfwSetMouseButtonCallback(window,mouse_button_callback);
}

#endif /* CALLBACKFUNC_H_ */
