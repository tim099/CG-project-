#include "class/texture/TextureMap.h"
#include <iostream>
TextureMap::TextureMap() {

}
TextureMap::~TextureMap() {
	std::map<std::string,Texture*>::iterator it=textures.begin();
	while(it!=textures.end()){
		delete (it->second);
		it++;
	}
}
void TextureMap::push_tex(std::string tex_name,Texture* tex){
	textures[tex_name]=tex;
}
Texture* TextureMap::get_tex(std::string tex_name){
	return textures[tex_name];
}
