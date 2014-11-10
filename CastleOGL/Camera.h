#pragma once
#include <GL/glew.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
typedef enum
{
	CAMERA_FORWARD,
	CAMERA_BACKWARD,
	CAMERA_LEFT,
	CAMERA_RIGHT
} CameraDirections;

class Camera
{
	GLfloat movementSpeed;
	GLfloat mouseSensitivity;
	void updateCameraVectors();
public:
	GLfloat yaw, pitch; 
	GLfloat zoom;
	GLfloat aspectRatio = 1.0f;
	GLfloat nearPlane = 0.1f;
	GLfloat farPlane = 1000.0f;

	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
	
	glm::mat4 getViewMatrix() const;
	void moveDirection(CameraDirections, GLfloat);
	void lookInDirection(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);
	void processMouseScroll(GLfloat);

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), 
		GLfloat yaw = -90.0f, GLfloat pitch = 0.0f) : 
			front(glm::vec3(0.0f, 0.0f, -1.0f)), 
			movementSpeed(5.0f), 
			mouseSensitivity(0.25f), 
			zoom(45.0f)
	{
		this->position = position;
		this->worldUp = up;
		this->yaw = yaw;
		this->pitch = pitch;
		this->updateCameraVectors();
	}
	~Camera() {}

	Camera& operator=(const Camera& other);
};

