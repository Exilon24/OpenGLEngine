#include "glm/fwd.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <gameobject.hpp>

enum CameraMode
{
	FirstPerson,
	Orbital,
	Static
};

class Camera
{
private:
	glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 direction = glm::normalize(this->transform.position - this->target);
	glm::mat4 perspective;	
	glm::mat4 view = glm::mat4(1.0f);
	float screenHeight = 600;
	float screenWidth = 600;
	float min;
	float max;

public:
	float fov;
	CameraMode cameraMode = FirstPerson;
	Transform transform;
	float camSpeed = 4;
	float dampening = 0.2;

	Camera(float screenHeight, float screenWidth, float fov, float min, float max);
	void setDimentions(float height, float width);
	glm::mat4 LookAt(glm::vec3 vector);
	glm::mat4 LookAt(float x, float y, float z);
	glm::mat4 calculateView();
	void setTarget(GameObject target);
	void setTarget(glm::vec3 target);
	void setTarget(float x, float y, float z);
	
	float getMin();
	float getMax();

	~Camera() = default;
};
