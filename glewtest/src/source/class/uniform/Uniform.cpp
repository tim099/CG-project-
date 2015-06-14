#include "class/uniform/Uniform.h"
#include "class/tim/string/String.h"
Uniform::Uniform() {

}
Uniform::~Uniform() {

}
void Uniform::sentMat4Arr(GLuint programID,glm::mat4* MatArr,int num,std::string name){
	//Tim::String::gen_array_num(name,0);
	GLuint UNI=glGetUniformLocation(programID,name.c_str());
	for(int i=0;i<num;i++){
		glUniformMatrix4fv(UNI+i,1,GL_FALSE,&((MatArr[i])[0][0]));
	}
}
