#include "Transform.h"

Transform::~Transform()
{
}

void Transform::translateTo(glm::vec3 transLoc)
{
	this->position = transLoc;
}

void Transform::translateBy(glm::vec3 transLoc){
	this->position += transLoc;
}
void Transform::rotateAbout(GLfloat angle, GLfloat x = 0, GLfloat y = 0, GLfloat z = 0) {
	this->rotation.angle += angle;
	this->rotation.axis = glm::vec3(x, y, z);

}
void Transform::scaleBy(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0) {
	this->scale += glm::vec3{ x, y, z };
}