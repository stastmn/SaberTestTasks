//Реализуйте функцию расчета усредненных нормалей для вершин меша, заданного индексированными треугольниками. 

#include <iostream>
#include "CalcNormals.h"
int main()
{
	int nfaces = 36;
	int faces[36] = { 5,3,1, 3,8,4, 7,6,8, 2,8,6, 1,4,2, 5,2,6, 5,7,3, 3,7,8, 7,5,6, 2,4,8, 1,3,4, 5,1,2 };
	int nverts = 8;
	vec3 verts[8] = {
		{ 1.000000f, 1.000000f, -1.000000f},
		{ 1.000000f, -1.000000f, -1.000000f},
		{ 1.000000f, 1.000000f, 1.000000f},
		{ 1.000000f, -1.000000f, 1.000000f},
		{ -1.000000f, 1.000000f, -1.000000f},
		{ -1.000000f, -1.000000f, -1.000000f},
		{ -1.000000f, 1.000000f, 1.000000f},
		{ -1.000000f, -1.000000f, 1.000000f} };

	vec3 normals[8];

	calc_mesh_normals(normals, verts, faces, nverts, nfaces);

	std::cout << "Calculated normals:\n";
	for (int i = 0; i < nverts; i++) {
		
		std::cout << normals[i].x << " " << normals[i].y << " " << normals[i].z << "\n";
	}

	system("pause");
	return 0;
}
