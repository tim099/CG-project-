#include "class/texture/TextureMap.h"
#include "class/texture/texture2D/Texture2D.h"
#include "class/tim/file/File.h"
#include "class/tim/string/String.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
TextureMap::TextureMap() {

}
TextureMap::~TextureMap() {
	std::map<std::string,Texture*>::iterator it=textures.begin();
	while(it!=textures.end()){
		delete (it->second);
		it++;
	}
}
void TextureMap::Load_texture(std::istream &is,const std::string &folder_path){
	char line[100];
	std::string name,path;
	Tim::String::getline(is,line,sizeof(line),true,true);
	if(!strcmp(line,"Texture Name:")){
		Tim::String::getline(is,line,sizeof(line),true,true);
		name=std::string(line);
	}else{
		std::cerr<<"Load_texture no Texture Name!!"<<line<<std::endl;
		return;
	}
	Tim::String::getline(is,line,sizeof(line),true,true);
	if(!strcmp(line,"TexturePath:")){
		Tim::String::getline(is,line,sizeof(line),true,true);
		path=folder_path+std::string(line);
	}else{
		std::cerr<<"Load_texture no TexturePath!!"<<line<<std::endl;
		return;
	}
	push_tex(name,Texture2D::loadBMP(path.c_str()));
}
void TextureMap::Load_texture_script(std::string script_path){
	char line[500];
	std::filebuf file;

	file.open(script_path.c_str(),std::ios::in);
	std::istream is(&file);
	Tim::String::getline(is,line,sizeof(line),true,true);
	if(strcmp(line,"#LOADTEXTURE_SCRIPT")){
		std::cerr<<"Load_texture Fail:"<<script_path<<std::endl;
		return;
	}
	std::string folder_path;
	Tim::String::getline(is,line,sizeof(line),true,true);
	if(strcmp(line,"Header:")){
		std::cerr<<"Load_texture No Header!!"<<line<<std::endl;
		return;
	}
	Tim::String::getline(is,line,sizeof(line),true,true);
	if(strcmp(line,"FolderPath:")){
		std::cerr<<"Load_texture No FolderPath!!"<<line<<std::endl;
		return;
	}
	Tim::String::getline(is,line,sizeof(line),true,true);
	folder_path=std::string(line);
	while(!is.eof()){
		Tim::String::getline(is,line,sizeof(line),true,true);
		if(!strcmp(line,"#END")){
			break;
		}
		if(!strcmp(line,"Texture:")){
			Load_texture(is,folder_path);
		}
	}

	file.close();
}
void TextureMap::push_tex(std::string tex_name,Texture* tex){
	textures[tex_name]=tex;
}
Texture* TextureMap::get_tex(std::string tex_name){
	return textures[tex_name];
}
