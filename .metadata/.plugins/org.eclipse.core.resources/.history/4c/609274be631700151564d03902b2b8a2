#include "class/texture/TextureMap.h"
#include "class/texture/texture2D/Texture2D.h"
#include "class/tim/file/File.h"
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
void TextureMap::Load_texture(std::fstream &file,const std::string &folder_path){
	char line[100];
	std::string name,path;
	Tim::File::getline(file,line,sizeof(line),true,true);
	if(!strcmp(line,"Texture Name:")){
		Tim::File::getline(file,line,sizeof(line),true,true);
		name=std::string(line);
		std::cout<<"name:"<<name<<std::endl;
	}else{
		std::cerr<<"Load_texture no Texture Name!!"<<line<<std::endl;
		return;
	}
	Tim::File::getline(file,line,sizeof(line),true,true);
	if(!strcmp(line,"TexturePath:")){
		Tim::File::getline(file,line,sizeof(line),true,true);
		path=folder_path+std::string(line);
		std::cout<<"path:"<<path<<std::endl;
	}else{
		std::cerr<<"Load_texture no TexturePath!!"<<line<<std::endl;
		return;
	}
	push_tex(name,Texture2D::loadBMP(path.c_str()));
}
void TextureMap::Load_texture_script(std::string script_path){
	char line[500];//std::istream t;
	std::fstream file;
	file.open(script_path.c_str(),std::ios::in);
	//file.getline(line,sizeof(line));
	Tim::File::getline(file,line,sizeof(line),true,true);
	if(strcmp(line,"#LOADTEXTURE_SCRIPT")){
		std::cerr<<"Load_texture Fail:"<<script_path<<std::endl;
		return;
	}
	std::string folder_path;
	Tim::File::getline(file,line,sizeof(line),true,true);
	if(strcmp(line,"Header:")){
		std::cerr<<"Load_texture No Header!!"<<line<<std::endl;
		return;
	}
	Tim::File::getline(file,line,sizeof(line),true,true);
	if(strcmp(line,"FolderPath:")){
		std::cerr<<"Load_texture No FolderPath!!"<<line<<std::endl;
		return;
	}
	Tim::File::getline(file,line,sizeof(line),true,true);
	folder_path=std::string(line);
	while(!file.eof()){
		Tim::File::getline(file,line,sizeof(line),true,true);
		if(!strcmp(line,"#END")){
			std::cout<<"END"<<std::endl;
			break;
		}
		if(!strcmp(line,"Texture:")){
			Load_texture(file,folder_path);
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
