#include "glad/glad.h"
#include <algorithm>
#include <iostream>
#include <gameobject.hpp>

#define STB_IMAGE_IMPLEMENTATION
// #include <stb/stb_image.h>

GameObject::GameObject(Window container) : vao(0), vbo(0), ebo(0)
{
    glfwMakeContextCurrent(container.getWindow());
    std::cout << "Creating gameobject...\n";
    std::cout << "vao: " << this->vao << " vbo: " << this->vbo << " ebo: " << this->ebo << "\n";
    glGenVertexArrays(1, &this->vao);
    glGenBuffers(1, &this->vbo);
    glGenBuffers(1, &this->ebo);
    std::cout << "Sucessfully created gameobject!\n";
}

void GameObject::Draw(Shader shader, glm::mat4 &view)
{
    Bind();
    shader.use();
    glm::mat4 model = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
                                0.0f, 1.0f, 0.0f, 0.0f,
                                0.0f, 0.0f, 1.0f, 0.0f ,
                                this->transform.position.x, this->transform.position.y, this->transform.position.z, 1.0f);

    model = glm::rotate(model, glm::radians(this->transform.rotationEuler.x), glm::vec3(1,0,0));
    model = glm::rotate(model, glm::radians(this->transform.rotationEuler.y), glm::vec3(0,1,0));
    model = glm::rotate(model, glm::radians(this->transform.rotationEuler.z), glm::vec3(0,0,1));

    shader.setMat4("view", view);
    shader.setMat4("model", model);

    glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
}

void GameObject::Bind()
{
    glBindVertexArray(this->vao);
}

void GameObject::BufferMeshData()
{
    std::cout << "Buffering vertices: " << &this->vertices[0] << "\n";
    Bind();
    float vertex[this->vertices.size()];
    std::copy(this->vertices.begin(), this->vertices.end(), vertex);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices), &this->indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    std::cout << "Sucessfully bound vertices\n";
    std::cout << "vao: " << this->vao << " vbo: " << this->vbo << " ebo: " << this->ebo << "\n";
}

void GameObject::SetIndices(std::vector<unsigned int> indices)
{
    this->indices = indices;
}
void GameObject::setVertices(std::vector<float> vertices)
{
    this->vertices = vertices;
}

GameObject::~GameObject()
{
    glDeleteVertexArrays(1, &this->vao);
    glDeleteBuffers(1, &this->vbo);
    glDeleteBuffers(1, &this->vao);
}

