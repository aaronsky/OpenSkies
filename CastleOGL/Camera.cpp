#include "Camera.h"

glm::mat4 Camera::getViewMatrix() const
{
	return glm::lookAt(this->position, this->position + this->front, this->worldUp);
}

void Camera::lookInDirection(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch) {
	xoffset *= this->mouseSensitivity;
	yoffset *= this->mouseSensitivity;
	this->yaw += xoffset;
	this->pitch += yoffset;
	if (constrainPitch) {
		if (this->pitch > 89.0f)
			this->pitch = 89.0f;
		if (this->pitch < -89.0f)
			this->pitch = -89.0f;
	}
	this->updateCameraVectors();
}

void Camera::moveDirection(CameraDirections direction, GLfloat deltaTime)
{
	GLfloat velocity = this->movementSpeed * deltaTime;
	if (direction == CAMERA_FORWARD)
		this->position += this->front * velocity;
	if (direction == CAMERA_BACKWARD)
		this->position -= this->front * velocity;
	if (direction == CAMERA_LEFT)
		this->position -= this->right * velocity;
	if (direction == CAMERA_RIGHT)
		this->position += this->right * velocity;
}

void Camera::processMouseScroll(GLfloat yoffset)
{
	if (this->zoom >= 1.0f && this->zoom <= 45.0f)
		this->zoom -= yoffset;
	if (this->zoom <= 1.0f)
		this->zoom = 1.0f;
	if (this->zoom >= 45.0f)
		this->zoom = 45.0f;
}

void Camera::updateCameraVectors()
{
	// Calculate the new Front vector
	glm::vec3 front;
	front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	front.y = sin(glm::radians(this->pitch));
	front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->front = glm::normalize(front);
	// Also re-calculate the Right and Up vector
	this->right = glm::normalize(glm::cross(this->front, this->worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	this->up = glm::normalize(glm::cross(this->front, this->right));
}

Camera& Camera::operator=(const Camera& other) {
	this->movementSpeed = other.movementSpeed;
	this->mouseSensitivity = other.mouseSensitivity;

	this->yaw = other.yaw;
	this->pitch = other.pitch;
	this->zoom = other.zoom;
	this->aspectRatio = other.aspectRatio;
	this->nearPlane = other.nearPlane;
	this->farPlane = other.farPlane;

	this->position = other.position;
	this->front = other.front;
	this->up = other.up;
	this->right = other.right;
	this->worldUp = other.worldUp;
	return *this;
}