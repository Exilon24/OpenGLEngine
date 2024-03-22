#ifndef ENGINE_MATH 
#define ENGINE_MATH

#include "assimp/vector3.h"
#include "glm/ext/vector_float3.hpp"

namespace EngineMath {
	float lerp(const float a, const float b, const float t);

	// Assimp aiVector3D to glm::vec3
	glm::vec3 serializeAssimpVector(const aiVector3D& aiVec);

}

#endif // !
