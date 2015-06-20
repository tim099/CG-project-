#include "class/tim/file/File.h"
#include "class/tim/string/String.h"
#include <cstring>
namespace Tim {

File::File() {

}
File::~File() {

}
bool File::getline(std::fstream &file,char* line,int size,bool skip_blank_line,bool skip_blankspace){
	if(file.eof())return false;
	if(skip_blank_line){
		while(!file.eof()){
			file.getline(line,size);
			if(strlen(line)!=0)break;
		}
	}else{
		file.getline(line,size);
	}
	if(skip_blankspace){
		Tim::String::skip_blank_space(line);
	}
	return true;
}




} /* namespace Tim */
