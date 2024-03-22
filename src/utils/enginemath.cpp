#include <enginemath.hpp>

float EngineMath::lerp(const float a, const float b, const float t) 
{
    return a + (b - a) * t;
}
	
// Assimp aiVector3D to glm::vec3
glm::vec3 EngineMath::serializeAssimpVector(const aiVector3D& aiVec)
{
	glm::vec3 vector;
	vector.x = aiVec.x;
	vector.y = aiVec.y;
	vector.z = aiVec.z;
	return vector;
}
