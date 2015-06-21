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
bool String::getline(std::istream &is,char* line,int size,bool skip_blankline,bool skip_blankspace){
	if(is.eof())return false;
	if(skip_blankline){
		while(!is.eof()){
			is.getline(line,size);
			if(strlen(line)!=0)break;
		}
	}else{
		is.getline(line,size);
	}
	if(skip_blankspace){
		Tim::String::skip(line,std::string(" 	"));
	}
	return true;
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
std::string String::substring(std::string str,int start,int end){
	std::string sub;
	for(int i=start;i<end;i++){
		sub+=str[i];
	}
	return sub;
}
std::vector<std::string> String::split(std::string str,std::string delimiter){
	std::vector<std::string> out;
	/*int i=0,prev=0;
	char* cur_at=str.c_str();
	while(true){
		i=skip(cur_at,delimiter);
		if(i>0)cur_at+=i;
		else break;
	}*/

	return out;
}
int String::skip(char *str,std::string cskip){
	bool start=false;
	int i,cur_at=0;
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
	}
	return cur_at;
}

}
