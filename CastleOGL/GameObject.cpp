#include "GameObject.h"

GameObject::~GameObject()
{
	//while (!meshes.empty()) delete meshes.back(), meshes.pop_back();
}

void GameObject::update(GLfloat dT)
{
	for (auto &mesh : meshes)
	{
		transform->rotateAbout(dT * 50.f, 0.5f, 0.2f, -0.3f);
	}
}

void GameObject::draw(const Camera camera, vector<Light> nearbyLights)
{
	material.bindTextures();
	glUniform3fv(glGetUniformLocation(material.shader.program, "viewPos"), 1, glm::value_ptr(camera.position));
	for (int i = 0; i < nearbyLights.size(); i++)
	{
		Light light = nearbyLights[i];
		stringstream elementStream;
		string element;
		if (light.type == "direction")
		{
			elementStream << "dirLights[" << i << "].";
			element = elementStream.str();
			glUniform3fv(glGetUniformLocation(material.shader.program, string(element + "direction").c_str()), 1, glm::value_ptr(light.position));
		}
		else
		{
			elementStream << "pointLights[" << i - 1 << "].";
			element = elementStream.str();
			glUniform1f(glGetUniformLocation(material.shader.program, string(element + "constant").c_str()), light.constant);
			glUniform1f(glGetUniformLocation(material.shader.program, string(element + "linear").c_str()), light.linear);
			glUniform1f(glGetUniformLocation(material.shader.program, string(element + "quadratic").c_str()), light.quadratic);
			glUniform3fv(glGetUniformLocation(material.shader.program, string(element + "position").c_str()), 1, glm::value_ptr(light.position));
		}
		glUniform3fv(glGetUniformLocation(material.shader.program, string(element + "ambient").c_str()), 1, glm::value_ptr(light.ambient));
		glUniform3fv(glGetUniformLocation(material.shader.program, string(element + "diffuse").c_str()), 1, glm::value_ptr(light.diffuse));
		glUniform3fv(glGetUniformLocation(material.shader.program, string(element + "specular").c_str()), 1, glm::value_ptr(light.specular));
	}

	glm::mat4 projMat = glm::perspective(camera.zoom, camera.aspectRatio, camera.nearPlane, camera.farPlane);
	const glm::mat4 viewMat = camera.getViewMatrix();

	glUniformMatrix4fv(glGetUniformLocation(material.shader.program, "view"), 1, GL_FALSE, glm::value_ptr(viewMat));
	glUniformMatrix4fv(glGetUniformLocation(material.shader.program, "projection"), 1, GL_FALSE, glm::value_ptr(projMat));

	for (auto &mesh : meshes) {
		mesh->draw(*(this->transform), &(material.shader));
	}
	material.unbindTextures();
}
