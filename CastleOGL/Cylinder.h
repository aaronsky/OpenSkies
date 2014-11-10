#pragma once
#include "Mesh.h"
class Cylinder :
	public Mesh
{
	float radius;
	int radialDivisions;
	int heightDivisions;
public:
	void initShape() override;
	Cylinder(float rad, int radDiv, int heightDiv) : radius(rad), radialDivisions(radDiv), heightDivisions(heightDiv) {
		this->initShape();
		this->init();
	}
	~Cylinder() {}
};

