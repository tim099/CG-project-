#ifndef LIGHTCONTROL_H_
#define LIGHTCONTROL_H_

#define MAX_LIGHT 100
#include <class/light/PointLight.h>
#include <class/light/ParallelLight.h>
#include <vector>
class LightControl {
public:
	LightControl(float draw_dis);
	virtual ~LightControl();
	void sent_uniform(GLuint programID,glm::vec3 camera_pos);
	unsigned parallel_light_size()const;
	unsigned point_light_size()const;
	PointLight* get_point_light(int i)const;
	ParallelLight* get_parallel_light(int i)const;
	void push_point_light(PointLight* l);
	void push_parallel_light(ParallelLight* l);
	std::vector<ParallelLight*>parallel_lights;
protected:
	std::vector<PointLight*>point_lights;

	float draw_dis;
};

#endif /* LIGHTCONTROL_H_ */
