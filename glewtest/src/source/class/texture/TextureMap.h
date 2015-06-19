#ifndef TEXTUREMAP_H_
#define TEXTUREMAP_H_
#include "class/texture/texture.h"
#include <string>
#include <map>
class TextureMap {
public:
	TextureMap();
	virtual ~TextureMap();

	void push_tex(std::string tex_name,Texture* tex);
	Texture* get_tex(std::string tex_name);
protected:
	std::map<std::string,Texture*>textures;
};

#endif /* TEXTUREMAP_H_ */
