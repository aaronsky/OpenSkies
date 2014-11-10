#include "InputHandler.h"

InputHandler& InputHandler::getInstance()
{
	static InputHandler instance;
	return instance;
}

void InputHandler::keyboardImpl(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Game* game = reinterpret_cast<Game *>(glfwGetWindowUserPointer(window));
	game->handleKey(window, key, action);
}

void InputHandler::mouseInitImpl()
{
	//Hide the cursor for FPS-style mouselook
	//glutSetCursor(GLUT_CURSOR_NONE);
}

void InputHandler::mouseclickImpl(GLFWwindow* window, int button, int action, int mods)
{
}

void InputHandler::mouselookImpl(GLFWwindow* window, double xpos, double ypos)
{
	Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	game->camera.lookInDirection(xoffset, yoffset);
}
void InputHandler::mousescrollImpl(GLFWwindow* window, GLdouble yoffset) {
	Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));
	game->camera.processMouseScroll(yoffset);
}

void InputHandler::keyboard(GLFWwindow* window, int key, int scancode, int action, int mods) {
	getInstance().keyboardImpl(window, key, scancode, action, mods);
}
void InputHandler::mouseInit() {
	getInstance().mouseInitImpl();
}
void InputHandler::mouseclick(GLFWwindow* window, int button, int action, int mods) {
	getInstance().mouseclickImpl(window, button, action, mods);
}
void InputHandler::mouselook(GLFWwindow* window, double xpos, double ypos) {
	getInstance().mouselookImpl(window, xpos, ypos);
}
void InputHandler::mousescroll(GLFWwindow* window, double xoffset, double yoffset) {
	getInstance().mousescrollImpl(window, yoffset);
}