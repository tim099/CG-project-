#include <class/tim/string/String.h>
#include <class/tim/math/Math.h>
#include <cmath>
#include <algorithm>

namespace Tim {
String::String() {

}
String::~String() {

}
void String::gen_array_num(char *str,int num){
	str[0]='[';
	int len=Tim::Math::get_len(num);
	for(int i=1;i<=len;i++){
		str[i]=(char)('0'+Tim::Math::get_val_at(num,len-i));
	}
	str[len+1]=']';
	str[len+2]='\0';
}


}
