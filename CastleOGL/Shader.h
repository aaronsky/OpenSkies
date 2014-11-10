#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

using namespace std;

class Shader
{
public:
	//Shader
	GLuint program;
	Shader() {}
	
	void makeActive();
	static Shader& makeShader(const GLchar*, const GLchar*);
	~Shader(void) {}
};