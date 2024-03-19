#include "assimp/material.h"
#include "glad/glad.h"
#include <iostream>
#include <model.hpp>

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
{
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;

    initializeMesh();
}

void Mesh::initializeMesh()
{
    glGenVertexArrays(1, &this->vao);
    glGenBuffers(1, &this->vbo);
    glGenBuffers(1, &this->ebo);

    glBindVertexArray(this->vao);
    glBindBuffer(GL_ARRAY_BUFFER, vao);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)offsetof(Vertex, Normal));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)offsetof(Vertex, textureCoord));
}

void Mesh::draw(Shader& shader)
{
    GLuint diffN{1};
    GLuint specN{1};

    unsigned int count = 0;
    for (Texture tex : this->textures)
    {
        std::string number;

        if (tex.name == "diffuse")
            number = std::to_string(diffN++);
        else if (tex.name == "spec")
            number = std::to_string(specN++);
        
        shader.setInt((tex.name + number).c_str(), count);
        count++;
    }

    glActiveTexture(GL_TEXTURE0);

    glBindVertexArray(this->vao);
    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

Model::Model(const char* path)
{
    loadModel(path);    
}

Model::Model(Mesh mesh)
{
    this->meshVector.push_back(mesh);
}

void Model::setShader(Shader& shader)
{
    this->currentShader = shader;
}

void Model::draw()
{
    this->currentShader.use();
    for (Mesh i : this->meshVector)
    {
        i.draw(this->currentShader);
    }
}

bool Model::loadModel(std::string path)
{
    Assimp::Importer import;
    const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode )
    {
        std::cerr << "MODEL LOADING: FAILED TO LOAD MODEL";
        return 1;
    }

    this->dir = path.substr(0, path.find_last_of('/'));
    processNode(scene->mRootNode, scene);
    return 0;
}
void Model::processNode(aiNode *node, const aiScene *scene)
{
    for (unsigned int i = 0; i < scene->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[i];
        this->meshVector.push_back(processMesh(mesh, scene));
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

void Model::loadMaterial(aiMaterial* material, aiTextureType type, std::string name, std::vector<Texture>& texturesVec)
{
    std::vector<Texture> textures;
    for (unsigned int i; i < material->GetTextureCount(type); i++)
    {
        aiString str;
        material->GetTexture(type, i, &str);
        
        bool loaded = false;
        for (Texture i: texturesLoaded)
        {
            if (std::strcmp(i.assetImportString.data(), str.C_Str()) == 0)
            {
                loaded = true;
                textures.push_back(i);
                break;
            }
        }
        if (!loaded)
        {
            Texture newText;
            newText.glObject = loadTextureImage(str.C_Str(), this->dir);
            newText.name = name;
            newText.assetImportString = str.C_Str();
            textures.push_back(newText);
            texturesLoaded.push_back(newText);
        }
    }
    texturesVec.insert(texturesVec.end(), textures.begin(), textures.end());
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    // Process the vertices. Normals and other bits of geometry are stored per vertex
    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        glm::vec3 bufferVector;

        bufferVector = EngineMath::serializeAssimpVector(mesh->mVertices[i]);
        vertex.Position = bufferVector;

        if (mesh->HasNormals())
        {
            bufferVector = EngineMath::serializeAssimpVector(mesh->mNormals[i]); 
            vertex.Normal = bufferVector;
        }

        if (mesh->HasTextureCoords(0))
        {
            vertex.textureCoord = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
        }

        vertices.push_back(vertex);
    }
    // process the indices which are stored if primitive faces
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; j++)
        {
            indices.push_back(mesh->mFaces[i].mIndices[j]);
        }
    }

    // Process textures
    aiMaterial * material = scene->mMaterials[mesh->mMaterialIndex];
    

    loadMaterial(material, aiTextureType_DIFFUSE, "diffuse", textures);
    loadMaterial(material, aiTextureType_HEIGHT, "normal", textures);
    loadMaterial(material, aiTextureType_SPECULAR, "specular", textures);
    loadMaterial(material, aiTextureType_AMBIENT, "normal", textures);

    return Mesh(vertices, indices, textures);
}

unsigned int loadTextureImage(const char* path, const std::string directory)
{
    std::string filename = std::string(path);
    filename = directory + '/' + path;

    GLuint texture;
    glGenTextures(1, &texture);

    int width, height, nrComp;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComp, 0); 

    if (data)
    {
        GLenum format;
        switch(nrComp)
        {
            case 1:
                format = GL_RED;
            case 2:
                format = GL_RGB;
            case 3:
                format = GL_RGBA;
            default:
                std::cerr << "No color channels";
        }

        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else {
        std::cerr << "Failed to load texture";
    }
    return texture;
}

