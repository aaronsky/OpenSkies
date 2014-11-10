#include "Cube.h"

void Cube::initShape()
{
	//front
	for (int i = 0; i < subdivisions; i++)
	{
		for (int j = 0; j < subdivisions; j++) {
			//x0 and x1 are theta min and theta max
			//y0 and y1 are phi min and phi max
			float x0 = glm::mix(-0.5f, 0.5f, i / float(subdivisions)),
				x1 = glm::mix(-0.5f, 0.5f, (i + 1) / float(subdivisions)),
				y0 = glm::mix(-0.5f, 0.5f, j / float(subdivisions)),
				y1 = glm::mix(-0.5f, 0.5f, (j + 1) / float(subdivisions)),
				u0 = glm::mix(0.0f, 1.0f, i / float(subdivisions)),
				u1 = glm::mix(0.0f, 1.0f, (i + 1) / float(subdivisions)),
				v0 = glm::mix(0.0f, 1.0f, j / float(subdivisions)),
				v1 = glm::mix(0.0f, 1.0f, (j + 1) / float(subdivisions));

			//z is .5 for the front of the cube
			float z = .5;


			glm::vec3 vert0 = { x0, y0, z };
			glm::vec3 vert1 = { x1, y0, z };
			glm::vec3 vert2 = { x0, y1, z };
			glm::vec3 vert3 = { x1, y1, z };


			//v0, v1, v2 and v3 are the 3 vector corners of the square patch
			//front 
			addSquare({ { vert0.x, vert0.y, z }, {}, { u0, v0 } },
			{ { vert1.x, vert1.y, z }, {}, { u1, v0 } },
			{ { vert2.x, vert2.y, z }, {}, { u1, v1 } },
			{ { vert3.x, vert3.y, z }, {}, { u0, v1 } });

			//back
			// -x/y/-z
			addSquare({ { -vert0.x, vert0.y, -z }, {}, { u0, v0 } },
			{ { -vert1.x, vert1.y, -z }, {}, { u1, v0 } },
			{ { -vert2.x, vert2.y, -z }, {}, { u1, v1 } },
			{ { -vert3.x, vert3.y, -z }, {}, { u0, v1 } });

			//top
			// x/-z/y
			addSquare({ { vert0.x, -z, vert0.y }, {}, { u0, v0 } },
			{ { vert1.x, -z, vert1.y }, {}, { u1, v0 } },
			{ { vert2.x, -z, vert2.y }, {}, { u1, v1 } },
			{ { vert3.x, -z, vert3.y }, {}, { u0, v1 } });

			//bottom
			// -x/z/y
			addSquare({ { -vert0.x, z, vert0.y }, {}, { u0, v1 } },
			{ { -vert1.x, z, vert1.y }, {}, { u1, v0 } },
			{ { -vert2.x, z, vert2.y }, {}, { u1, v1 } },
			{ { -vert3.x, z, vert3.y }, {}, { u0, v1 } });

			//right
			// -z/y/x
			addSquare({ { -z, vert0.y, vert0.x }, {}, { u0, v0 } },
			{ { -z, vert1.y, vert1.x }, {}, { u1, v0 } },
			{ { -z, vert2.y, vert2.x }, {}, { u1, v1 } },
			{ { -z, vert3.y, vert3.x }, {}, { u0, v1 } });

			//left
			// z/y/-x
			addSquare({ { z, vert0.y, -vert0.x }, {}, { u0, v0 } },
			{ { z, vert1.y, -vert1.x }, {}, { u1, v0 } },
			{ { z, vert2.y, -vert2.x }, {}, { u1, v1 } },
			{ { z, vert3.y, -vert3.x }, {}, { u0, v1 } });
		}
	}
}