#include <class/tim/math/Math.h>

namespace Tim {

Math::Math() {


}
Math::~Math() {

}
glm::mat4 Math::BiasMat(){
	glm::mat4 biasMat(
	0.5, 0.0, 0.0, 0.0,
	0.0, 0.5, 0.0, 0.0,
	0.0, 0.0, 0.5, 0.0,
	0.5, 0.5, 0.5, 1.0);
	return biasMat;
}
float Math::max(glm::vec3 v){
	if(v.x>v.y){
		if(v.x>v.z){
			return v.x;
		}else{
			return v.z;
		}
	}else{
		if(v.y>v.z){
			return v.y;
		}else{
			return v.z;
		}
	}
}
int Math::get_len(int val){
	int len=1;
	while(val>=10){
		val/=10;
		len++;
	}
	return len;
}
int Math::get_val_at(int val,int at){
	while(at>0){
		at--;
		val/=10;
	}
	return val%10;
}


} /* namespace Tim */
