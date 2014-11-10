#include "Material.h"

Material::~Material()
{
	while (!textures.empty()) textures.back().reset(), textures.pop_back();
}

void Material::bindTextures() 
{
	shader.makeActive();
	glUniform1f(glGetUniformLocation(shader.program, "material.diffuse"), diffuse);
	glUniform1f(glGetUniformLocation(shader.program, "material.specular"), specular);
	glUniform1f(glGetUniformLocation(shader.program, "material.shininess"), shininess);
	for (unsigned int i = 0; i < this->textures.size(); ++i)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, this->textures[i]->id);
	}

}

void Material::unbindTextures() 
{
	for (int i = this->textures.size() - 1; i >= 0; --i)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
