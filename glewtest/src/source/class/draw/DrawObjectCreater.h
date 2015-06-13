#ifndef DRAWOBJECTCREATER_H_
#define DRAWOBJECTCREATER_H_
#include <class/draw/DrawObject.h>
#include "class/texture/texture.h"
#include <vector>
class BufferObject;
class Model;
class DrawObjectCreater {
public:
	DrawObjectCreater();
	virtual ~DrawObjectCreater();
	DrawObject *creat_draw_obj(const char* obj_path,const char* tex_path,float size,bool to_o);
	std::vector<BufferObject*> b_objs;
	std::vector<Model*> m_objs;
	std::vector<Texture*> texturebuffers;
};

#endif /* DRAWOBJECTCREATER_H_ */
