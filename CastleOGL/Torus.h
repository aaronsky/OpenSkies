#pragma once
#include "Mesh.h"
class Torus :
	public Mesh
{
	float radiusTube;
	float radiusCenter;
	int subdivisions;
public:
	void initShape() override;
	Torus(float radTube, float radCenter, int subDiv) : radiusTube(radTube),
		radiusCenter(radCenter),
		subdivisions(subDiv) {
		this->initShape();
		this->init();
	}
	~Torus() {}
};

