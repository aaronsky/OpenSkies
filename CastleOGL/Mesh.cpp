#include "Mesh.h"

void Mesh::init()
{
	glGenVertexArrays(1, &vertexArrays);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &elementBuffer);

	glBindVertexArray(vertexArrays);

	GLsizei size = this->localContainer.size();
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(Vertex), &(this->localContainer[0]), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	for (int i = 0; i < size; i++)
		this->localIndexes.push_back(i);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLshort), &(this->localIndexes[0]), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));
	
	glBindVertexArray(0);
}

void Mesh::addTriangle(Vertex vert0, Vertex vert1, Vertex vert2)
{
	auto calculateNormals = [&]() {
		return glm::normalize(glm::cross(vert1.position - vert0.position, vert2.position - vert1.position));
	};

	vert0.normal = vert1.normal = vert2.normal = calculateNormals();

	localContainer.push_back(vert0);
	localContainer.push_back(vert1);
	localContainer.push_back(vert2);
}

void Mesh::addSquare(Vertex vert0, Vertex vert1, Vertex vert2, Vertex vert3)
{
	addTriangle(vert0, vert1, vert2);
	addTriangle(vert3, vert2, vert1);
}

void Mesh::draw(Transform transform, const Shader* shader)
{
	glBindVertexArray(vertexArrays);
	glm::mat4 model;
	model = glm::translate(model, transform.position);
	model = glm::rotate(model, transform.rotation.angle, transform.rotation.axis);
	model = glm::scale(model, transform.scale);
	glUniformMatrix4fv(glGetUniformLocation(shader->program, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glDrawElements(GL_TRIANGLES, this->localIndexes.size(), GL_UNSIGNED_SHORT, (GLvoid*)0);
	glBindVertexArray(0);
}
