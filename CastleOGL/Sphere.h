#pragma once
#include "Mesh.h"
class Sphere :
	public Mesh
{
	float radius;
	int slices;
	int stacks;
public:
	void initShape() override;

	Sphere(float rad, int sl, int st) : radius(rad),
		slices(sl),
		stacks(st) {
		this->initShape();
		this->init();
	}
	~Sphere() {}
};

