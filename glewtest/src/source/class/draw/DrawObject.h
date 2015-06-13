#ifndef DRAWOBJECT_H_
#define DRAWOBJECT_H_
#include <vector>
#include <class/buffer/BufferObject.h>
#include <class/tim/math/Position.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
class Texture;
class DrawObject {
public:
	DrawObject(BufferObject* obj,Texture* texturebuffer);
	virtual ~DrawObject();
	static glm::mat4 model_matrix(Position* p);
	static void view(GLuint programID,glm::mat4 model_matrix);
	void draw_object(GLuint programID);
	void draw_shadow_map(GLuint programID);
	void push_position(Position p);
	void push_temp_position(Position p);
	void clear_position();
	void clear_temp_position();
	BufferObject *obj;
	bool draw_shadow;
protected:
	Texture* texturebuffer;
	void draw_vec(GLuint programID,std::vector<Position> &pos_v);
	std::vector<Position>m_pos;
	std::vector<Position>temp_pos;

};

#endif /* DRAWOBJECT_H_ */
