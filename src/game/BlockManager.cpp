#include "BlockManager.h"


BlockManager::BlockManager()
{

}

BlockManager::~BlockManager()
{

}

void BlockManager::init()
{
	grassTexture = new CubeTexture(
		"src/textures/cube/grass/right.png",
		"src/textures/cube/grass/left.png",
		"src/textures/cube/grass/top.png",
		"src/textures/cube/grass/bottom.png",
		"src/textures/cube/grass/front.png",
		"src/textures/cube/grass/back.png"
	);
}


void BlockManager::addBlock(BlockType blockType, glm::vec3 position)
{
	Block* block = new Block(blockType, position);
	block->setTexture(grassTexture);
	blocks.push_back(block);
}

void BlockManager::draw(Camera& camera, Shader& shader)
{
	for (unsigned int i = 0; i < blocks.size(); i++)
	{
		camera.matrix(shader, "camMatrix");
		blocks[i]->mesh->draw(shader);
	}
}