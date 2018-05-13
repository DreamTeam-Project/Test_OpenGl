#ifndef LIGHT_H
#define LIGHT_H

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

#include "Shader.h"
#include "Model.h"

using std::string;
using std::vector;

struct GlobalLight {
	GlobalLight(const vec3& dir = direction, const vec3& amb = ambient, 
		const vec3& diff = diffuse, const vec3& spec = specular) :
		direction_(dir), ambient_(amb), diffuse_(diff), specular_(spec) {  }
	vec3 direction_;
	vec3 ambient_;
	vec3 diffuse_;
	vec3 specular_;
};

struct PointLight {
	PointLight() = delete;
	PointLight(GameModel* mod, const vec3& pos, const vec3& diff, const vec3& amb,
		const vec3& spec, float con, float lin, float quad) : 
	model(mod), position_(pos), ambient_(amb), diffuse_(diff), 
		specular_(spec), constant_(con), quadratic_(quad) {  }
	GameModel* model;
	vec3 position_;
	vec3 ambient_;
	vec3 diffuse_;
	vec3 specular_;
	float constant_;
	float linear_;
	float quadratic_;
};

struct SpotLight {
	SpotLight() = delete;
	SpotLight(GameModel* mod, const vec3& pos, const vec3& diff, const vec3& amb,
		const vec3& dir, const vec3& spec, float con, float lin, float quad, float cut, float out) :
		model(mod), position_(pos), direction_(dir), ambient_(amb), diffuse_(diff), specular_(spec), 
		constant_(con), quadratic_(quad), cutOff_(glm::cos(glm::radians(cut))), outerCutOff_(glm::cos(glm::radians(out))) 
	{  }
	GameModel* model;
	vec3 position_;
	vec3 direction_;
	vec3 ambient_;
	vec3 diffuse_;
	vec3 specular_;
	float constant_;
	float linear_;
	float quadratic_;
	float cutOff_;
	float outerCutOff_;
};

class GameLight {
public:
	GameLight(const GameLight&) = delete;
	GameLight(const GameLight&&) = delete;
	GameLight() : Global(GlobalLight()) {  }
	vector<PointLight> PointLights;
	vector<SpotLight> SpotLights;
	GlobalLight Global;
	void SetLight(const GameShader& shader);
private:
	void SetPointLights(const GameShader& shader);
	void SetSpotLights(const GameShader& shader);
	void SetGlobalLight(const GameShader& shader);
};

#endif