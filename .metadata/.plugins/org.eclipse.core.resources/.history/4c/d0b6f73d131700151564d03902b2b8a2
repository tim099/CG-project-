#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <class/draw/DrawObject.h>
#include <class/buffer/Buffer.h>
#include "class/texture/texture.h"
#include <iostream>
DrawObject::DrawObject(BufferObject* _obj,Texture* _texturebuffer) {
	obj=_obj;
	texturebuffer=_texturebuffer;
	draw_shadow=true;
}
DrawObject::~DrawObject() {
	clear_position();
	clear_temp_position();
	delete obj;
}
void DrawObject::view(GLuint programID,glm::mat4 M){
    glUniformMatrix4fv(glGetUniformLocation(programID,"M"),1,GL_FALSE,&(M[0][0]));
}
void DrawObject::clear_position(){
	for(unsigned i=0;i<m_pos.size();i++){
		delete m_pos.at(i);
	}
	m_pos.clear();
}
void DrawObject::clear_temp_position(){
	for(unsigned i=0;i<temp_pos.size();i++){
		delete temp_pos.at(i);
	}
	temp_pos.clear();
}
Position* DrawObject::push_position(Position* p){
	m_pos.push_back(p);
	return p;
}
Position* DrawObject::push_temp_position(Position* p){
	temp_pos.push_back(p);
	return p;
}
void DrawObject::draw_vec(GLuint programID,std::vector<Position*> &pos_v){
	for(unsigned i=0;i<pos_v.size();i++){
		view(programID,pos_v.at(i)->PosMat());
		obj->draw(programID);
	}
}
void DrawObject::draw_shadow_map(GLuint programID){
	if(!draw_shadow)return;
	Buffer::bind_vtbuffer(obj->vtbuffer);
	draw_vec(programID,m_pos);
	draw_vec(programID,temp_pos);
	glDisableVertexAttribArray(0);//vertexbuffer
}
void DrawObject::draw_object(GLuint programID){
	obj->bind_buffer(programID);
	texturebuffer->sent_uniform(programID,0,"myTextureSampler");

	draw_vec(programID,m_pos);
	draw_vec(programID,temp_pos);

	//clear_temp_position();
	Buffer::disable_all_buffer();
}
