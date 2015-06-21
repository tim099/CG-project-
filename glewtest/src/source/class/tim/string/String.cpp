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
bool String::within(char c,const std::string& str){
	for(unsigned j=0;j<str.length();j++){
		if(c==str[j])return true;
	}
	return false;
}
void String::skip(char *str,std::string cskip){
	bool start=false;
	int i,cur_at=0;
	std::cout<<"skip start"<<str<<std::endl;
	for(i=0;str[i]!='\0';i++){
		if(!start){//not start yet
			if(!within(str[i],cskip))start=true;//start
		}
		if(start){
				str[cur_at++]=str[i];
		}
	}
	while(within(str[cur_at],cskip)){
		cur_at--;
	}
	if(start!=-1){
		str[cur_at]='\0';
		std::cout<<"cur_at="<<cur_at<<","<<str<<std::endl;
	}
}
void String::skip_blank_space(char *str){
	skip(str,std::string(" 	"));
}

}
