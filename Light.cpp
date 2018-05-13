#include "Light.h"

void GameLight::SetPointLights(const GameShader& shader) {
	string buf;
	for (uint i = 0; i < PointLights.size(); i++) {
		buf = string("pointLights[") + to_string(i) + string("].");
		shader.setVec3(buf + "position", PointLights[i].position_ + PointLights[i].model->place_);
		shader.setVec3(buf + "ambient", PointLights[i].ambient_);
		shader.setVec3(buf + "diffuse", PointLights[i].diffuse_);
		shader.setVec3(buf + "specular", PointLights[i].specular_);
		shader.setFloat(buf + "constant", PointLights[i].constant_);
		shader.setFloat(buf + "linear", PointLights[i].linear_);
		shader.setFloat(buf + "quadratic", PointLights[i].quadratic_);
	}
}

void GameLight::SetSpotLights(const GameShader& shader) {
	string buf;
	for (uint i = 0; i < SpotLights.size(); i++) {
		buf = string("spotLights[") + to_string(i) + string("].");
		shader.setVec3(buf + "position", SpotLights[i].position_ + SpotLights[i].model->place_);
		shader.setVec3(buf + "direction", SpotLights[i].direction_/* * SpotLights[i].model->quat_*/);
		shader.setVec3(buf + "ambient", SpotLights[i].ambient_);
		shader.setVec3(buf + "diffuse", SpotLights[i].diffuse_);
		shader.setVec3(buf + "specular", SpotLights[i].specular_);
		shader.setFloat(buf + "constant", SpotLights[i].constant_);
		shader.setFloat(buf + "linear", SpotLights[i].linear_);
		shader.setFloat(buf + "quadratic", SpotLights[i].quadratic_);
	}
}

void GameLight::SetGlobalLight(const GameShader& shader) {
	shader.setVec3("dirLight.direction", Global.direction_);
	shader.setVec3("dirLight.ambient", Global.ambient_);
	shader.setVec3("dirLight.diffuse", Global.diffuse_);
	shader.setVec3("dirLight.specular", Global.specular_);
}

void GameLight::SetLight(const GameShader& shader) {
	shader.setInt("numPointLights", PointLights.size());
	shader.setInt("numSpotLights", SpotLights.size());
	SetGlobalLight(shader);
	SetPointLights(shader);
	SetSpotLights(shader);
}