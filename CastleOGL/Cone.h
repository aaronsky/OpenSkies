#pragma once
#include "Mesh.h"
class Cone :
	public Mesh
{
	float radius;
	int radialDivisions;
	int heightDivisions;
public:
	void initShape() override;
	Cone(float rad, int radDiv, int heightDiv) : radius(rad),
		radialDivisions(radDiv),
		heightDivisions(heightDiv) {
		this->initShape();
		this->init();
	}
	~Cone() {}
};

