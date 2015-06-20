#include "class/buffer/BufferObject.h"
#include "class/buffer/Buffer.h"
#include "class/model/Model.h"
#include "class/texture/Texture.h"
#include <iostream>
BufferObject::BufferObject(GLuint _vtbuffer,GLuint _uvbuffer,GLuint _texturebuffer
		,GLuint _nbuffer,int _vertex_num,glm::vec4 _mat){
	vtbuffer=_vtbuffer;
	uvbuffer=_uvbuffer;
	vertex_num=_vertex_num;
	vnbuffer=_nbuffer;
	mat=_mat;
}
BufferObject::BufferObject(Model *m){
	vtbuffer=Buffer::gen_buffer(m->vtBuffer,m->vtdatasize());
	uvbuffer=Buffer::gen_buffer(m->uvBuffer,m->uvdatasize());
	vnbuffer=Buffer::gen_buffer(m->vnBuffer,m->vndatasize());
	vertex_num=m->vtlen();
	mat=m->mat;
}
BufferObject::~BufferObject() {
    glDeleteBuffers(1,&vtbuffer);
    glDeleteBuffers(1,&uvbuffer);
    glDeleteBuffers(1,&vnbuffer);
}
void BufferObject::bind_buffer(GLuint programID){
	Buffer::bind_vtbuffer(vtbuffer);
	Buffer::bind_uvbuffer(uvbuffer);
	Buffer::bind_vnbuffer(vnbuffer);
	glUniform4f(glGetUniformLocation(programID,"mat"),mat.x,mat.y,mat.z,mat.w);
}
void BufferObject::draw(GLuint programID){
	glDrawArrays(GL_TRIANGLES,0,vertex_num);
	//glDrawArrays(GL_LINES,0,vertex_num);
	//glDrawArrays(GL_POINTS,0,vertex_num);
}
