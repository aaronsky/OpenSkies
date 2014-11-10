#pragma once

using namespace std;

#include <vector>
#include <iostream>

#include "Transform.h"
#include "Light.h"
#include "Material.h"
#include "Camera.h"

static const float PI = 3.14159f;
static const float TWO_PI = 6.28318530718f;
static const float PI_2 = 1.57079632679f;

inline float lerp(const float min, const float max, const float t)
{
	return min + t * (max - min);
}

class Mesh
{
public:
	GLuint vertexBuffer;
	GLuint vertexArrays;
	GLuint elementBuffer;

	vector<Vertex> localContainer;
	vector<GLshort> localIndexes;

	//Initialize local uniform data (model-world transformation data)
	void init();

	void addTriangle(Vertex, Vertex, Vertex);
	void addSquare(Vertex vert0, Vertex vert1, Vertex vert2, Vertex vert3);
	
	virtual void initShape() = 0;
	
	void draw(Transform transform, const Shader* shader);
	Mesh(void) {}
	~Mesh(void) {}
};