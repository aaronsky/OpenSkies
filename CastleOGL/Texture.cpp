#include "Texture.h"

unordered_map<string, shared_ptr<Texture>> Texture::loadedTextures;

shared_ptr<Texture> Texture::loadTexture(const char* fileName, const char* type) {
	//if filename in map of textures
		//return that
	if (loadedTextures.find(fileName) != loadedTextures.end())
		return loadedTextures[fileName];
	shared_ptr<Texture> tex = shared_ptr<Texture>(new Texture());
	glGenTextures(1, &(tex->id));
	int width, height;
	unsigned char* image;
	image = SOIL_load_image(fileName, &width, &height, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, tex->id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	tex->type = type;
	loadedTextures.insert(std::make_pair(fileName, tex));
	return tex;
}
