#pragma once
#include "Vertex.h"
struct Rotation {
	GLfloat angle;
	glm::vec3 axis;
};
class Transform
{
public:
	glm::vec3 position;
	Rotation rotation;
	glm::vec3 scale;
	Transform(glm::vec3 _position = { 0.0f, 0.0f, 0.0f }, Rotation _rotation = { 0.0f, { 0.0f, 0.0f, 0.0f } }, glm::vec3 _scale = { 1.0f, 1.0f, 1.0f }) : position (_position), rotation (_rotation), scale(_scale) {}
	~Transform();
	void translateTo(glm::vec3);
	void translateBy(glm::vec3);
	void rotateAbout(GLfloat angle, GLfloat x, GLfloat y, float z);
	void scaleBy(GLfloat x, GLfloat y, GLfloat z);
};

