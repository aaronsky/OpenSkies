#pragma once
#include <string>

#include <GL\glew.h>
#include "glm\glm.hpp"

using namespace std;

class Light
{
public:
	string type;
	glm::vec3 position, ambient, diffuse, specular;
	GLfloat constant, linear, quadratic;
	Light(string type = "point", 
		glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 ambient = glm::vec3(0.05f, 0.05f, 0.05f),
		glm::vec3 diffuse = glm::vec3(0.8f, 0.8f, 0.8f),
		glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f),
		GLfloat constant = 1.0f,
		GLfloat linear = 0.09,
		GLfloat quadratic = 0.032) {
		this->type = type;
		this->position = position;
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
		this->constant = constant;
		this->linear = linear;
		this->quadratic = quadratic;
	}
	~Light();
};

