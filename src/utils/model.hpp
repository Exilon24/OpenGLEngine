#ifndef GAME_OBJECT_ENGINE
#define GAME_OBJECT_ENGINE

#include "glad/glad.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <shader.hpp>


struct Vertex{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 textureCoord;
	Vertex() = default;
	Vertex(const glm::vec3& vector);
};

struct Texture{
	GLuint glObject;
	std::string name;
	std::string assetImportString;
};

class Mesh{
	public:
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		std::vector<Texture> textures;

		Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
		void draw(Shader& shader);

	private:
		GLuint vao, ebo, vbo;
	
		void initializeMesh();
};


class Model{
public:
	Model() = default;
	Model(const char* path);
	Model(Mesh mesh);
	void draw(glm::mat4& model, glm::mat4& view);
	void setShader(Shader& shader);
	
private:
	std::vector<Mesh> meshVector;
	std::vector<Texture> texturesLoaded;
	Shader currentShader;
	std::string dir;

	bool loadModel(std::string path);
	void loadMaterial(aiMaterial* material, aiTextureType type, std::string name, std::vector<Texture>& texturesVec);
	unsigned int loadTextureImage(const char* path, const std::string directory);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
};
#endif // !GAME_OBJECT_ENGINE
