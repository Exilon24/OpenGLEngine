#include <Camera.hpp>
#include <enginemath.hpp>

constexpr glm::vec3 up(0,1,0);

Camera::Camera(float screenHeight, float screenWidth, float fov, float min, float max) 
:screenWidth(screenWidth), screenHeight(screenHeight) , max(max), min(min), fov(fov)
{
    this->transform.localRight = glm::normalize(glm::cross(up, this->direction));
    this->transform.localUp = glm::cross(this->direction, this->transform.localRight);
    this->perspective = glm::perspective(glm::radians(fov), (float)screenHeight / (float)screenWidth, min, max);
}

glm::mat4 Camera::LookAt(glm::vec3 target)
{
    return glm::lookAt(this->transform.position, target, up);
}

glm::mat4 Camera::LookAt(float x, float y, float z){
    return glm::lookAt(this->transform.position, glm::vec3(x, y, z), up);
}

glm::mat4 Camera::calculateView()
{
   switch (this->cameraMode) 
    {
    case FirstPerson:
        transform.localFront.x = EngineMath::lerp(
                transform.localFront.x, 
                cos(glm::radians(transform.rotationEuler.x)) * cos(glm::radians(transform.rotationEuler.y)), dampening); 
        transform.localFront.y = EngineMath::lerp(
                transform.localFront.y, sin(glm::radians(transform.rotationEuler.y)), dampening);
        transform.localFront.z = EngineMath::lerp(
                transform.localFront.z, sin(glm::radians(transform.rotationEuler.x)) * cos(glm::radians(transform.rotationEuler.y)), dampening);
        transform.localFront = glm::normalize(transform.localFront);

        return LookAt(this->transform.position + this->transform.localFront);
        break;
    case Orbital:
        return LookAt(target);
    default:
            std::cerr << "NO CAMERA TYPE SELECTED";
        break;
    } 
}

void Camera::setTarget(glm::vec3 target)
{
    this->target = target;
}
void Camera::setTarget(GameObject target)
{
    setTarget(target.transform.position);
}
void Camera::setTarget(float x, float y, float z)
{
    setTarget(glm::vec3(x, y, z));
}

void Camera::setDimentions(float height, float width)
{
    this->screenHeight = height;
    this->screenWidth = width;
}

float Camera::getMin()
{
    return this->min;
}

float Camera::getMax()
{
    return this->max;
}
