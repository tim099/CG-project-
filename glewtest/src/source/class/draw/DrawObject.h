#ifndef DRAWOBJECT_H_
#define DRAWOBJECT_H_
#include <vector>
#include <class/buffer/BufferObject.h>
#include <class/tim/math/Position.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
class Texture;
class Shader;
class DrawObject {
public:
	DrawObject(BufferObject* obj,Texture* texture,Texture* NormalMap=0);
	virtual ~DrawObject();
	//static glm::mat4 model_matrix(Position* p);
	static void view(GLuint programID,glm::mat4 model_matrix);
	void draw_object(Shader *shader);
	void draw_shadow_map(GLuint programID);
	Position* push_position(Position* p);
	Position* push_temp_position(Position* p);
	void clear_position();
	void clear_temp_position();
	BufferObject *obj;
	bool draw_shadow;
protected:
	Texture* texture;
	Texture* NormalMap;
	void draw_vec(GLuint programID,std::vector<Position*> &pos_v);
	std::vector<Position*>m_pos;
	std::vector<Position*>temp_pos;

};

#endif /* DRAWOBJECT_H_ */
