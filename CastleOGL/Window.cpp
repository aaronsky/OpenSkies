#include "Window.h"


Window::Window(const char* title, int width, int height)
{
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window)
	{
		throw EXIT_FAILURE;
	}
	else {
		glfwMakeContextCurrent(window);
		
		initializeCallbacks(window);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		glewExperimental = GL_TRUE;
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		}

		glViewport(0, 0, width, height);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		game = new Game();
		
		glfwSetWindowUserPointer(window, game);
		
		previous = glfwGetTime();

		glClearColor(.392f, .584f, .929f, 1.0f);
	}
}

Window::~Window()
{
}

void Window::gameLoop()
{
	while (!glfwWindowShouldClose(window)){
		update();
		draw(window);
		glfwPollEvents();
	}
	delete game;
}

void Window::error(int error, const char* description)
{
	fputs(description, stderr);
}

void Window::window_close(GLFWwindow* window)
{
	if (glfwWindowShouldClose(window)) {
		glfwDestroyWindow(window);
		glfwTerminate();
		exit(EXIT_SUCCESS);
	}
}

void Window::initializeCallbacks(GLFWwindow* window)
{
	glfwSetErrorCallback(error);
	glfwSetWindowCloseCallback(window, window_close);
	glfwSetMouseButtonCallback(window, &InputHandler::mouseclick);
	glfwSetScrollCallback(window, &InputHandler::mousescroll);
	glfwSetCursorPosCallback(window, &InputHandler::mouselook);
	glfwSetKeyCallback(window, &InputHandler::keyboard);
}

void Window::update() {
	game->update();
}

void Window::draw(GLFWwindow* window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	game->draw();

	glfwSwapBuffers(window);
}
