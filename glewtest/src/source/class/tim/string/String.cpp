#include "class/tim/string/String.h"
#include "class/tim/math/Math.h"
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
namespace Tim {
String::String() {

}
String::~String() {

}
void String::gen_array_num(char *str,int num){
	sprintf(str,"[%d]",num);
}
void String::skip_blank_space(char *str){
	int i,start=-1;
	for(i=0;true;i++){
		if(start==-1&&str[i]!=' '&&str[i]!='\t'){//not start yet
			start=i;
			if(i==0)break;
		}
		if(start!=-1){
			str[i-start]=str[i];
		}
		if(str[i]=='\0'){
			break;
		}
	}
	//if(start!=-1)str[i-start]='\0';
}

}
