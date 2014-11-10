#include "Shader.h"

Shader& Shader::makeShader(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath)
{
	string vertexCode, fragmentCode;

	try
	{
		ifstream vertexShaderFile(vertexShaderPath),
			fragmentShaderFile(fragmentShaderPath);
		stringstream vertexShaderStream, fragmentShaderStream;
		vertexShaderStream << vertexShaderFile.rdbuf();
		fragmentShaderStream << fragmentShaderFile.rdbuf();
		vertexShaderFile.close();
		fragmentShaderFile.close();
		vertexCode = vertexShaderStream.str();
		fragmentCode = fragmentShaderStream.str();
	}
	catch (exception e) {
		cout << "Error: Shader file not read successfully" << endl;
	}
	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();

	GLuint vertex, fragment;
	GLint success;
	GLchar infoLog[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		cout << "Vertex Shader Compilation Failed:\n" << infoLog << endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		cout << "Fragment Shader Compilation Failed:\n" << infoLog << endl;
	}

	Shader shader = Shader();
	shader.program = glCreateProgram();
	glAttachShader(shader.program, vertex);
	glAttachShader(shader.program, fragment);
	glLinkProgram(shader.program);
	glGetProgramiv(shader.program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader.program, 512, NULL, infoLog);
		cout << "Program Linking Failed:\n" << infoLog << endl;
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return shader;
}

void Shader::makeActive() { 
	glUseProgram(this->program); 
}

