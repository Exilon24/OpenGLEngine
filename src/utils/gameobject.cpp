#include <gameobject.hpp>


void GameObject::Draw(glm::mat4 &view)
{
    glm::mat4 model = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
                                0.0f, 1.0f, 0.0f, 0.0f,
                                0.0f, 0.0f, 1.0f, 0.0f ,
                                this->transform.position.x, this->transform.position.y, this->transform.position.z, 1.0f);

    model = glm::rotate(model, glm::radians(this->transform.rotationEuler.x), glm::vec3(1,0,0));
    model = glm::rotate(model, glm::radians(this->transform.rotationEuler.y), glm::vec3(0,1,0));
    model = glm::rotate(model, glm::radians(this->transform.rotationEuler.z), glm::vec3(0,0,1));
    model = glm::scale(model, this->transform.size);
    
    this->objModel.draw(model, view);
}

GameObject::GameObject(const char* path)
{
    BufferMeshData(path);
}

void GameObject::BufferMeshData(const char* path)
{
    this->objModel = Model(path);
}

void GameObject::setShader(Shader& shader)
{
    std::cout << "Setting shader\n";
    this->objModel.setShader(shader);
}

