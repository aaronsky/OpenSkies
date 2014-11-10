#pragma once
#include <sstream>

#include "Torus.h"
#include "Cube.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Sphere.h"

class GameObject
{
public:
	vector<shared_ptr<Mesh>> meshes;
	Material material;
	shared_ptr<Transform> transform;
	GameObject() { transform = shared_ptr<Transform>(new Transform()); }
	GameObject(shared_ptr<Mesh> mesh) {
		meshes.push_back(mesh);
		transform = shared_ptr<Transform>(new Transform());
	}
	GameObject(vector<shared_ptr<Mesh>> newMeshes) {
		meshes.insert(meshes.end(), newMeshes.begin(), newMeshes.end());
	}
	~GameObject();
	void update(GLfloat dT);
	void draw(const Camera camera, vector<Light> nearbyLights);
};

