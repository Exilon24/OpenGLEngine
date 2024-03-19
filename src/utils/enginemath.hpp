#ifndef ENGINE_MATH 
#define ENGINE_MATH
#include "assimp/vector3.h"
#include "glm/ext/vector_float3.hpp"

namespace EngineMath {
	float lerp(const float a, const float b, const float t) 
	{
		return a + (b - a) * t;
	}
	
// Assimp aiVector3D to glm::vec3
	glm::vec3 serializeAssimpVector(const aiVector3D& aiVec)
	{
		glm::vec3 vector;
		vector.x = aiVec.x;
		vector.y = aiVec.y;
		vector.z = aiVec.z;
		return vector;
	}
}

#endif // !
