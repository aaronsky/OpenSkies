#pragma once

#include "GameObject.h"

class Game
{
public:
	Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
	vector<Light> lights;
	vector<shared_ptr<GameObject>> gameObjects;

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	void initLocalUniforms();

	void update();
	void draw();

	void handleKey(GLFWwindow*, int, int);

	Game();
	~Game();
};

