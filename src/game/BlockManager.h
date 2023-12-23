#pragma once
#include "Block.h"
#include "../Camera.h"

class BlockManager
{
public:
	BlockManager();
	~BlockManager();

	void init();

	void addBlock(BlockType blockType, glm::vec3 position);
	void draw(Camera& camera, Shader& shader);
private:
	std::vector<Block*> blocks;

	CubeTexture* grassTexture;
};

