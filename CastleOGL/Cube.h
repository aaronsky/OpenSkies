#pragma once
#include "Mesh.h"

class Cube :
	public Mesh
{
	int subdivisions;
public:
	void initShape() override;
	Cube(int subdiv) : subdivisions(subdiv) {
		this->initShape();
		this->init();
	}
	~Cube() {}
};