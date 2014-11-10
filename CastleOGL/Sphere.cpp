#include "Sphere.h"

void Sphere::initShape()
{
	auto getSphereX = [&](const float theta, const float phi) {
		return radius * cos(phi) * cos(theta);
	};
	auto getSphereY = [&](const float theta, const float phi) {
		return radius * cos(phi) * sin(theta);
	};
	auto getSphereZ = [&](const float phi) {
		return radius * sin(phi);
	};
	//Iterate over every i,j square patch on the surface
	for (int i = 0; i < slices; i++)
	{
		for (int j = 0; j < stacks; j++)
		{
			//t0 and t1 are theta min and theta max
			//p0 and p1 are phi min and phi max
			float t0 = glm::mix(0.0f, TWO_PI, i / float(slices)),
				t1 = glm::mix(0.0f, TWO_PI, (i + 1) / float(slices)),
				p0 = glm::mix(-PI_2, PI_2, j / float(stacks)),
				p1 = glm::mix(-PI_2, PI_2, (j + 1) / float(stacks)),
				u0 = glm::mix(0.0f, 1.0f, i / float(slices)),
				u1 = glm::mix(0.0f, 1.0f, (i + 1) / float(slices)),
				v0 = glm::mix(0.0f, 1.0f, j / float(stacks)),
				v1 = glm::mix(0.0f, 1.0f, (j + 1) / float(stacks));

			Vertex vert0, vert1, vert2, vert3;
			vert0.position = { getSphereX(t0, p0), getSphereY(t0, p0), getSphereZ(p0) };
			vert0.normal = {};
			vert0.texCoords = { u0, v0 };

			vert1.position = { getSphereX(t1, p0), getSphereY(t1, p0), getSphereZ(p0) };
			vert1.normal = {};
			vert1.texCoords = { u1, v0 };

			vert2.position = { getSphereX(t0, p1), getSphereY(t0, p1), getSphereZ(p1) };
			vert2.normal = {};
			vert2.texCoords = { u1, v1 };

			vert3.position = { getSphereX(t1, p1), getSphereY(t1, p1), getSphereZ(p1) };
			vert3.normal = {};
			vert3.texCoords = { u0, v1 };

			addSquare(vert0, vert1, vert2, vert3);
		}
	}
}