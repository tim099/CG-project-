#ifndef TEST_H_
#define TEST_H_

#include <iostream>
#include <cstdio>
#include <cmath>
#include <GL/glew.h>
#include <GL/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "headers/callback/callBackFunc.h"
#include "class/shader/Shader.h"
#include "class/window/Window.h"
#include "class/texture/Texture.h"
#include "class/texture/texture2D/Texture2D.h"
#include "class/texture/TextureMap.h"
#include "class/camera/Camera.h"
#include "class/model/Model.h"
#include "class/model/obj/Obj.h"
#include "class/model/cube/CubeModel.h"
#include "class/buffer/Buffer.h"
#include "class/buffer/BufferObject.h"
#include "class/buffer/frameBuffer/FrameBuffer.h"
#include "class/input/keyboard/Keyboard.h"
#include "class/input/mouse/Mouse.h"
#include "class/draw/DrawObject.h"
#include "class/draw/DrawObjectCreater.h"
#include "class/tim/math/Math.h"
#include "class/tim/string/String.h"
#include "class/light/Light.h"
#include "class/light/PointLight.h"
#include "class/light/LightControl.h"
#include "class/uniform/Uniform.h"
const int MX=300,MY=50,MZ=300;
const double CUBE_SIZE=1.0;
class Test {

public:
	Test();
	virtual ~Test();
	static void creat_tex(TextureMap* texmap);
	void input(Camera *camera);
	void load_map();
	void creat_map_object(int px,int pz,int size);
	void creat_cube_obj();
	void draw_map(Camera *camera);
	void set_obj_pos(Camera *camera);
	void update_map(Camera *camera);
	void draw_all_objects(FrameBuffer *FBO,Camera *camera,double &time);
	void ParallelLights_shadow_map(GLuint programID,FrameBuffer* SFBO,std::vector<ParallelLight*>&lights
			,Camera *camera,glm::mat4 *LVP,double &time);
	void PointLight_shadow_maps(GLuint programID,FrameBuffer* SFBO,PointLight *light,glm::mat4 PLVP[6]);
	void prepare_draw_obj();
	void creat_shader();
	void creat_light();
	void Mainloop();
private:
	std::vector<Model*>models;
	std::vector<BufferObject*>b_objs;
	std::vector<DrawObject*>d_objs;
	LightControl* lightControl;
	PointLight *camlight;
	PointLight *sunlight;
	ParallelLight *s_light;
	KeyBoard *keyboard;
	Mouse *mouse;
	DrawObjectCreater *DOC;

	DrawObject* look_at;
	DrawObject* base;
	DrawObject* sun;
	DrawObject* tiger;
	DrawObject* stars;
	DrawObject* galaxy;
	DrawObject* dmaps[50][50];

	CubeModel *cube;

	std::vector<GLuint>shaders;
	TextureMap* texmap;
	GLuint cur_shader;
	GLuint shaderBasic,shaderNormalMapping,shader2D,shaderShadowMapping;
	GLuint shadercubeShadowMapping,shaderTest;
	Window *window;
	Camera *camera;
	double tiger_ry;
	double shadow_dis;
	int range;
	bool map[MX][MY][MZ];
	bool stop_the_sun;
	bool to_sobel;
	int shader_at;

};

#endif /* TEST_H_ */