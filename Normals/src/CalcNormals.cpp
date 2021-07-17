#include "CalcNormals.h"
#include <cmath>
#include <unordered_map>
#include <vector>



vec3 crossProduct(vec3 first, vec3 second) {
	//we use right hand coordinate system
	vec3 answer = { first.y*second.z - first.z*second.y,
					first.z*second.x - first.x*second.z,
					first.x*second.y - first.y*second.x };

	return answer;
}

float lenght(vec3 vector)
{
	float tmp = pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2);
	return sqrt(tmp);
}


void calc_mesh_normals(vec3* normals, const vec3* verts, const int* faces, int nverts, int nfaces) {

	//use this unordered_map for detecting what faces vertex 'touch' 
	std::unordered_map<vec3, std::vector<int>> verticeInFaces;
	//here we cache normals for each face
	std::unordered_map<int, vec3> faceWithNormal;

	//i+=3 because we have triplets of indices for each face
	for (int i = 0; i < nfaces; i += 3) {

		const int* face = faces + i;
		//-1 because indexes starts from 1, not 0
		vec3 edge1 = verts[face[1] - 1] - verts[face[0] - 1];
		vec3 edge2 = verts[face[2] - 1] - verts[face[0] - 1];

		vec3 faceNormal = crossProduct(edge1, edge2);

		faceWithNormal[i] = faceNormal;

		verticeInFaces[verts[face[0] - 1]].emplace_back(i);
		verticeInFaces[verts[face[1] - 1]].emplace_back(i);
		verticeInFaces[verts[face[2] - 1]].emplace_back(i);

	}

	for (int i = 0; i < nverts; i++) {

		auto tmp = verticeInFaces[verts[i]];
		vec3 normal = { 0,0,0 };
		for (auto iterator = tmp.begin(); iterator != tmp.end(); iterator++) {
			normal = normal + faceWithNormal[*iterator];
		}
		float len = lenght(normal);
		if (len != 0)
			normals[i] = normal / len;
		else
			normals[i] = normal;
	}


}


vec3 operator-(vec3 first, vec3 second) {
	vec3 answer = { first.x - second.x,first.y - second.y , first.z - second.z };
	//answer.x = second.x - first.x;
	//answer.y = second.y - first.y;
	//answer.z = second.z - first.z;

	return answer;
}

vec3 operator+(vec3 first, vec3 second) {
	vec3 answer = { second.x + first.x,second.y + first.y , second.z + first.z };
	//answer.x = second.x - first.x;
	//answer.y = second.y - first.y;
	//answer.z = second.z - first.z;

	return answer;
}

vec3 operator/(vec3 vec, float num)
{
	vec3 ans = { vec.x / num, vec.y / num, vec.z / num };
	return ans;
}




