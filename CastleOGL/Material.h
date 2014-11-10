#pragma once
#include <vector>
#include <memory>
#include "Shader.h"
#include "Texture.h"

class Material
{
public:
	Shader shader;
	vector<shared_ptr<Texture>> textures;
	GLfloat diffuse;
	GLfloat specular;
	GLfloat shininess;

	Material(GLfloat diffuse = 0.0f, GLfloat specular = 1.0f, GLfloat shininess = 64.0f) : diffuse(diffuse), specular(specular), shininess(shininess) {
		shader = Shader::makeShader("vshader.glsl", "fshader.glsl");
		textures.push_back(Texture::loadTexture("container2.png", "diffuse"));
		textures.push_back(Texture::loadTexture("container2_specular.png", "specular"));
	}
	~Material();
	void bindTextures();
	void unbindTextures();
};

