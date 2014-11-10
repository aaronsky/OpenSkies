#include "Torus.h"

void Torus::initShape()
{
	auto getTorusX = [&](const float theta, const float phi) {
		return (radiusTube * cos(theta) + radiusCenter) * cos(phi);
	};
	auto getTorusY = [&](const float theta, const float phi) {
		return (radiusTube * cos(theta) + radiusCenter) * sin(phi);
	};
	auto getTorusZ = [&](const float theta) {
		return radiusTube * sin(theta);
	};
	//Iterate over every i,j square patch on the surface
	for (int i = 0; i < subdivisions; i++)
	{
		for (int j = 0; j < subdivisions; j++)
		{

			float t0 = glm::mix(0.0f, TWO_PI, i / float(subdivisions)),
				t1 = glm::mix(0.0f, TWO_PI, (i + 1) / float(subdivisions)),
				p0 = glm::mix(0.0f, TWO_PI, j / float(subdivisions)),
				p1 = glm::mix(0.0f, TWO_PI, (j + 1) / float(subdivisions)),
				u0 = glm::mix(0.0f, 1.0f, i / float(subdivisions)),
				u1 = glm::mix(0.0f, 1.0f, (i + 1) / float(subdivisions)),
				v0 = glm::mix(0.0f, 1.0f, j / float(subdivisions)),
				v1 = glm::mix(0.0f, 1.0f, (j + 1) / float(subdivisions));

			Vertex vert0, vert1, vert2, vert3;
			vert0.position = { getTorusX(t0, p0), getTorusY(t0, p0), getTorusZ(t0) };
			vert0.normal = {};
			vert0.texCoords = {u0, v0};

			vert1.position = { getTorusX(t1, p0), getTorusY(t1, p0), getTorusZ(t1) };
			vert1.normal = {};
			vert1.texCoords = {u1, v0};

			vert2.position = { getTorusX(t0, p1), getTorusY(t0, p1), getTorusZ(t0) };
			vert2.normal = {};
			vert2.texCoords = {u1, v1};

			vert3.position = { getTorusX(t1, p1), getTorusY(t1, p1), getTorusZ(t1) };
			vert3.normal = {};
			vert3.texCoords = {u0, v1};

			addSquare(vert0, vert1, vert2, vert3);
		}
	}
}
