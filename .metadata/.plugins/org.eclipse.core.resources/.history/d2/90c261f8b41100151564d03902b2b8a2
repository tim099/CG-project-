#include <class/input/mouse/Mouse.h>
#include <iostream>
Mouse::Mouse() {
	prev_pos=glm::vec2(-1,-1);
	scroll=0;
	left=0,right=0,mid=0;
}
Mouse::~Mouse() {

}
glm::i16vec2 Mouse::pos_delta()const{
	if(prev_pos==glm::i16vec2(-1,-1))return glm::i16vec2(0,0);
	else return pos-prev_pos;
}
void Mouse::cursor_pos_callback(GLFWwindow* window,double x,double y){
	prev_pos=pos;
	pos.x=x;
	pos.y=y;
	//std::cout<<"mouse pos"<<pos.x<<","<<pos.y<<std::endl;
}
void Mouse::scroll_callback(GLFWwindow* window,double xoffset,double yoffset){
	//std::cout<<"scroll"<<xoffset<<","<<yoffset<<std::endl;
	scroll=yoffset;
}
void Mouse::mouse_button_callback(GLFWwindow* window,int button,int action,int mods){
		switch(button){
			case 0:
				if(action==1)left=true;
				else if(action==0)left=false;
				break;
			case 1:
				if(action==1)right=true;
				else if(action==0)right=false;
				break;
			case 2:
				if(action==1)mid=true;
				else if(action==0)mid=false;
				break;
			default:
				std::cout<<"unknow mouse but input"<<button<<std::endl;
		}

	//std::cout<<"button="<<button<<",action="<<action<<",mods="<<mods<<std::endl;
}
void Mouse::tic(){
	prev_pos=pos;
	scroll=0;
}
