#include <class/light/LightControl.h>
#include "class/tim/math/Math.h"
LightControl::LightControl(float _draw_dis) {
	draw_dis=_draw_dis;
}
LightControl::~LightControl() {
	for(unsigned i=0;i<point_lights.size();i++){
		delete point_lights.at(i);
	}
	for(unsigned i=0;i<parallel_lights.size();i++){
		delete parallel_lights.at(i);
	}
}
PointLight* LightControl::get_point_light(int i)const{
	return point_lights.at(i);
}
ParallelLight* LightControl::get_parallel_light(int i)const{
	return parallel_lights.at(i);
}
unsigned LightControl::parallel_light_size()const{
	return parallel_lights.size();
}
unsigned LightControl::point_light_size()const{
	return point_lights.size();
}
void LightControl::push_point_light(PointLight* l){
	point_lights.push_back(l);//lights.size()<MAX_LIGHT
}
void LightControl::push_parallel_light(ParallelLight* l){
	parallel_lights.push_back(l);
}
void LightControl::sent_uniform(GLuint programID,glm::vec3 camera_pos){
	//try to sort by dis and merge far light!!
    std::vector<glm::vec3>pointlight_pos;
    std::vector<glm::vec3>pointlight_color;
    std::vector<glm::vec3>parallellight_vec;
    std::vector<glm::vec3>parallellight_color;
    for(unsigned i=0;i<parallel_lights.size();i++){
    	parallellight_vec.push_back(parallel_lights.at(i)->vec);
    	parallellight_color.push_back(parallel_lights.at(i)->color);
    }
    for(unsigned i=0;i<point_lights.size();i++){
    	if(glm::length(camera_pos-point_lights.at(i)->pos)<draw_dis&&pointlight_pos.size()<MAX_LIGHT){
    		pointlight_pos.push_back(point_lights.at(i)->pos);
    		pointlight_color.push_back(point_lights.at(i)->color);
    	}
    }
    glUniform1i(glGetUniformLocation(programID,"parallellight_num"),parallellight_vec.size());
    glUniform3fv(glGetUniformLocation(programID,"parallellight_vec"),
    		parallellight_vec.size(),(const GLfloat*)(parallellight_vec.data()));
    glUniform3fv(glGetUniformLocation(programID,"parallellight_color"),
    		parallellight_color.size(),(const GLfloat*)(parallellight_color.data()));

    glUniform1i(glGetUniformLocation(programID,"pointlight_num"),pointlight_pos.size());
    glUniform3fv(glGetUniformLocation(programID,"pointlight_pos"),
    		pointlight_pos.size(),(const GLfloat*)(pointlight_pos.data()));
    glUniform3fv(glGetUniformLocation(programID,"pointlight_color"),
    		pointlight_color.size(),(const GLfloat*)(pointlight_color.data()));
}
