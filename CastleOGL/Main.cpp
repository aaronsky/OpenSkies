#include "Window.h"

int main(int argc, char **argv)
{
	if (!glfwInit())
		exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	Window window;
	try {
		InputHandler &input = InputHandler::getInstance();
		window = Window("My Castle", 800, 800);
	} catch (int error)
	{
		if (error == EXIT_FAILURE) {
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
	}
		
	window.gameLoop();

	glfwTerminate();
	
	exit(EXIT_SUCCESS);
}