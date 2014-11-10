#include "Cylinder.h"

void Cylinder::initShape()
{
	auto getCylinderX = [&](const float theta) {
		return radius * cos(theta);
	};
	auto getCylinderY = [&](const float theta) {
		return radius * sin(theta);
	};
	auto getCylinderZ = [&](const float height) {
		return height;
	};

	for (int v = 0; v < heightDivisions; v++) {
		for (int u = 0; u < radialDivisions; u++) {
			float t0 = glm::mix(0.0f, TWO_PI, (u) / float(radialDivisions)),
				t1 = glm::mix(0.0f, TWO_PI, (u + 1) / float(radialDivisions)),
				h0 = glm::mix(-0.5f, 0.5f, (v) / float(heightDivisions)),
				h1 = glm::mix(-0.5f, 0.5f, (v + 1) / float(heightDivisions)),
				u0 = glm::mix(0.0f, 1.0f, u / float(radialDivisions)),
				u1 = glm::mix(0.0f, 1.0f, (u + 1) / float(radialDivisions)),
				v0 = glm::mix(0.0f, 1.0f, v / float(heightDivisions)),
				v1 = glm::mix(0.0f, 1.0f, (v + 1) / float(heightDivisions));

			Vertex vert0, vert1, vert2, vert3;
			vert0.position = { getCylinderX(t0), getCylinderY(t0), getCylinderZ(h0) };
			vert0.normal = {};
			vert0.texCoords = { u0, v0 };

			vert1.position = { getCylinderX(t1), getCylinderY(t1), getCylinderZ(h0) };
			vert1.normal = {};
			vert1.texCoords = { u1, v0 };

			vert2.position = { getCylinderX(t0), getCylinderY(t0), getCylinderZ(h1) };
			vert2.normal = {};
			vert2.texCoords = { u1, v1 };

			vert3.position = { getCylinderX(t1), getCylinderY(t1), getCylinderZ(h1) };
			vert3.normal = {};
			vert3.texCoords = { u0, v1 };

			addSquare(vert0, vert1, vert2, vert3);
		}
	}
	for (int u = 0; u < radialDivisions; u++) {
		float t0 = glm::mix(0.0f, TWO_PI, (u) / float(radialDivisions)),
			t1 = glm::mix(0.0f, TWO_PI, (u + 1) / float(radialDivisions)),
			u0 = glm::mix(0.0f, 1.0f, u / float(radialDivisions)),
			u1 = glm::mix(0.0f, 1.0f, (u + 1) / float(radialDivisions));

		Vertex vert0, vert1, vert2, vert3;
		vert0.position = { 0.0f, 0.0f, 0.5f };
		vert0.normal = {};
		vert0.texCoords = { u0, u0 };

		vert1.position = { getCylinderX(t0), getCylinderY(t0), 0.5f };
		vert1.normal = {};
		vert1.texCoords = { u0, u1 };

		vert2.position = { getCylinderX(t1), getCylinderY(t1), 0.5f };
		vert2.normal = {};
		vert2.texCoords = { u1, u1 };

		addTriangle(vert0, vert1, vert2);
		vert0.position.z = vert1.position.z = vert2.position.z = -0.5f;
		addTriangle(vert0, vert1, vert2);
	}
}