#include <string>


struct vec3 {
	float x;
	float y;
	float z;

	bool operator==(const vec3 &other) const
	{
		return (x == other.x
			&& y == other.y
			&& z == other.z);
	}
};



vec3 operator-(vec3 first, vec3 second);
vec3 operator+(vec3 first, vec3 second);
vec3 operator/(vec3 vec, float num);

vec3 crossProduct(vec3 first, vec3 second);
float lenght(vec3 vector);



//
// Calculate smooth (average) per-vertex normals
//
// [out] normals - output per-vertex normals
// [in] verts - input per-vertex positions
// [in] faces - triangles (triplets of vertex indices)
// [in] nverts - total number of vertices (# of elements in verts and normals arrays)
// [in] nfaces - total number of faces (# of elements in faces array)
//
void calc_mesh_normals(vec3* normals, const vec3* verts, const int* faces, int nverts, int nfaces);


namespace std {

  template <>
  struct hash<vec3>
  {
    std::size_t operator()(const vec3& vec) const
    {
      using std::size_t;

	  return vec.x + vec.y + vec.z;
	}
  };

}

