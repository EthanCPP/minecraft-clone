#include "Block.h"


Block::Block(BlockType blockType, glm::vec3 position)
{
	std::vector<Vertex> vertices;

	vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 1.0f,  1.0f) });
	
	vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, -1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, -1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, -1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, -1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, -1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, -1.0f,  1.0f) });

	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });

	vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });

	vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 1.0f,  1.0f) });

	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  1.0f,  1.0f) });


	// Indices for vertices order
	std::vector<GLuint> indices;
	indices.insert(indices.end(), {
		0,  1,  2,
		3,  4,  5,

		18, 19, 20,
		21, 22, 23,

		12, 13, 14,
		15, 16, 17,

		6,  7,  8,
		9, 10, 11,

		30, 31, 32,
		33, 34, 35,

		24, 25, 26,
		27, 28, 29
	});

	mesh = new Mesh(vertices, indices);
	mesh->scale = 0.1;
	mesh->translate(position);

	/*CubeTexture cubeTexture(
		"src/textures/cube/grass/right.png",
		"src/textures/cube/grass/left.png",
		"src/textures/cube/grass/top.png",
		"src/textures/cube/grass/bottom.png",
		"src/textures/cube/grass/front.png",
		"src/textures/cube/grass/back.png"
	);

	mesh->setCubeTexture(&cubeTexture);*/
}

Block::~Block()
{

}

void Block::setTexture(CubeTexture* texture)
{
	mesh->setCubeTexture(texture);
}