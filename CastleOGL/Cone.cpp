#include "Cone.h"

void Cone::initShape()
{
	for (int v = 0; v < heightDivisions; v++) {
		for (int u = 0; u < radialDivisions; u++) {
			float t0 = glm::mix(0.0f, TWO_PI, (u) / float(radialDivisions)),
				t1 = glm::mix(0.0f, TWO_PI, (u + 1) / float(radialDivisions)),
				h0 = glm::mix(-0.5f, 0.5f, (v) / float(heightDivisions)),
				h1 = glm::mix(-0.5f, 0.5f, (v + 1) / float(heightDivisions)),
				i0 = glm::mix(radius, 0.0f, v / float(heightDivisions)),
				i1 = glm::mix(radius, 0.0f, (v + 1) / float(heightDivisions)),
				u0 = glm::mix(0.0f, 1.0f, (u) / float(radialDivisions)),
				u1 = glm::mix(0.0f, 1.0f, (u + 1) / float(radialDivisions)),
				v0 = glm::mix(0.0f, 1.0f, v / float(heightDivisions)),
				v1 = glm::mix(0.0f, 1.0f, (v + 1) / float(heightDivisions));

			Vertex vert0, vert1, vert2, vert3;
			vert0.position = { (radius - i0) * cos(t0), (radius - i0) * sin(t0), h0 };
			vert0.normal = {};
			vert0.texCoords = { u0, v0 };

			vert1.position = { (radius - i0) * cos(t1), (radius - i0) * sin(t1), h0 };
			vert1.normal = {};
			vert1.texCoords = { u1, v0 };

			vert2.position = { (radius - i1) * cos(t0), (radius - i1) * sin(t0), h1 };
			vert2.normal = {};
			vert2.texCoords = { u1, v1 };

			vert3.position = { (radius - i1) * cos(t1), (radius - i1) * sin(t1), h1 };
			vert3.normal = {};
			vert3.texCoords = { u0, v1 };

			addSquare(vert0, vert1, vert2, vert3);

			vert0.position = { 0, 0, .5 };
			vert1.position = { radius * cos(t0), radius * sin(t0), .5 };
			vert2.position = { radius * cos(t1), radius * sin(t1), .5 };

			//top
			addTriangle(vert0, vert1, vert2);
		}
	}
}