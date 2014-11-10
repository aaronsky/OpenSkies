#pragma once

#ifndef __glfw__
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#endif
#include <unordered_map>
#include "Game.h"

class InputHandler
{
private:
	GLfloat lastX = 400, lastY = 400;
	bool firstMouse = true;

	static std::unordered_map<int, bool> keys;
	InputHandler(void){}
	InputHandler(InputHandler const&);
	void operator=(InputHandler const&);
public:
	static InputHandler& getInstance();
	static void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
	void keyboardImpl(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseInit();
	void mouseInitImpl();
	static void mouseclick(GLFWwindow* window, int button, int action, int mods);
	void mouseclickImpl(GLFWwindow* window, int button, int action, int mods);
	static void mouselook(GLFWwindow* window, double xpos, double ypos);
	void mouselookImpl(GLFWwindow* window, double xpos, double ypos);
	static void mousescroll(GLFWwindow* window, double xoffset, double yoffset);
	void mousescrollImpl(GLFWwindow* window, double yoffset);
};

