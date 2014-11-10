#pragma once
#include <string>
#include <unordered_map>
#include <memory>

#include <GL/glew.h>
#include "glm/glm.hpp"
#include "soil\src\SOIL.h"

using namespace std;

class Texture
{
	Texture() {}
	static unordered_map<string, shared_ptr<Texture>> loadedTextures;
public:
	GLuint id;
	string type;

	static shared_ptr<Texture> loadTexture(const char* fileName, const char* type);
	~Texture() { glDeleteTextures(1, &id); }
};

