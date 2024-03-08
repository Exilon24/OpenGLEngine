#ifndef GAME_OBJECT
#define GAME_OBJECT
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/fwd.hpp"
#include "window.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include <shader.hpp>


struct Transform {
    glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f) ;
    glm::vec3 size = glm::vec3(0.0f,0.0f,0.0f);
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
    // Replace vertices and indices with a mesh or serialize mesh into vertices and indices
    GLuint vbo, vao, ebo;
    std::vector<unsigned int> indices;
    std::vector<float> vertices;

    std::vector<unsigned int> textures;
public:

    Transform transform;
    GameObject(Window container);
    GameObject() = delete;
    ~GameObject();
    void Bind();
    void BufferMeshData();
    void Draw(Shader shader, glm::mat4 &view);

    void SetIndices(std::vector<unsigned int> indices);
    void setVertices(std::vector<float> vertices);
};
#endif // !GAME_OBJECT
