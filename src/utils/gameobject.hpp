#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include <shader.hpp>
#include <model.hpp>


struct Transform {
    glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f) ;
    glm::vec3 size = glm::vec3(1.0f,1.0f,1.0f);
    glm::vec3 rotationEuler = glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 localUp = glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 localRight = glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 localFront = glm::vec3(0.0f,0.0f,0.0f);

    void translate(glm::vec3 vector);
    void scale(glm::vec3 vector);
    void rotate(glm::vec3 eulerAngles);
};

class GameObject
{
private:
    Model objModel;

public:
    GameObject(const char* path);

    Transform transform;

    void Bind();
    void BufferMeshData(const char* path);
    void Draw(glm::mat4 &view);

    void SetIndices(std::vector<unsigned int> indices);
    void setVertices(std::vector<float> vertices);
    void setShader(Shader& shader);
};
#endif // !GAME_OBJECT
