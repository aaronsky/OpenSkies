#include "Game.h"

inline void changePolygonMode()
{
	GLint polyMode;
	glGetIntegerv(GL_POLYGON_MODE, &polyMode);
	if (polyMode == GL_LINE) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else if (polyMode == GL_FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}

Game::Game()
{
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Torus(0.1f, 0.5f, 10)))));
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Sphere(0.5, 20, 20)))));
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Cylinder(0.5, 10, 10)))));
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Cone(0.5, 10, 10)))));
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Cube(1)))));
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Torus(0.1f, 0.5f, 10)))));
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Sphere(0.5, 5, 5)))));
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Cylinder(0.5, 10, 10)))));
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Cone(0.5, 10, 10)))));
	gameObjects.push_back(shared_ptr<GameObject>(new GameObject(shared_ptr<Mesh>(new Cube(20)))));

	glm::vec3 positions[] = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(2.0f, 5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f, 3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f, 2.0f, -2.5f),
		glm::vec3(1.5f, 0.2f, -1.5f),
		glm::vec3(-1.3f, 1.0f, -1.5f)
	};
	GLsizei positionCount = sizeof(positions) / sizeof(glm::vec3);
	for (int i = 0; i < positionCount; ++i)
	{
		gameObjects[i]->transform->position = positions[i];
	}
	lights.push_back(Light("direction", glm::vec3(1.2f, 1.0f, 2.0f)));
	lights.push_back(Light("point", glm::vec3(0.7f, 0.2f, 2.0f)));
	lights.push_back(Light("point", glm::vec3(2.3f, -3.3f, -4.0f)));
	lights.push_back(Light("point", glm::vec3(-4.0f, 2.0f, -12.0f)));
	lights.push_back(Light("point", glm::vec3(0.0f, 0.0f, -3.0f)));
}


Game::~Game()
{
}

void Game::initLocalUniforms()
{
}

void Game::update()
{
	GLfloat currentFrame = GLfloat(glfwGetTime());
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame; 
	for (auto &obj : gameObjects)
	{
		obj->update(deltaTime);
	}
}

void Game::draw()
{	
	for (auto &obj : gameObjects)
	{		
		obj->draw(camera, lights);
	}

}

void Game::handleKey(GLFWwindow* window, int key, int action) {
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		case GLFW_KEY_W:
		case GLFW_KEY_UP:
			camera.moveDirection(CAMERA_FORWARD, deltaTime);
			break;

		case GLFW_KEY_A:
		case GLFW_KEY_LEFT:
			camera.moveDirection(CAMERA_LEFT, deltaTime);
			break;

		case GLFW_KEY_S:
		case GLFW_KEY_DOWN:
			camera.moveDirection(CAMERA_BACKWARD, deltaTime);
			break;

		case GLFW_KEY_D:
		case GLFW_KEY_RIGHT:
			camera.moveDirection(CAMERA_RIGHT, deltaTime);
			break;

		case GLFW_KEY_SPACE:
			changePolygonMode();
			break;
		}
	}
}

