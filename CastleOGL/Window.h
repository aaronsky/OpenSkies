#pragma once

#include <algorithm>
#include "InputHandler.h"

#define OPTIMAL_TIME 1 / 60

class Window
{
	Game* game;
	GLFWwindow* window;

	double previous;
	double lag = 0.0;

	static void initializeCallbacks(GLFWwindow* window);

	static void error(int error, const char* description);
	static void window_close(GLFWwindow* window);

	void update();
	void draw(GLFWwindow*);
public:
	Window(const char*, int, int);
	Window(){ printf("uninitialized Windows DOn't do nothin\n"); }
	~Window();
	void gameLoop();
};

