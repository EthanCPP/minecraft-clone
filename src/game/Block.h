#pragma once
#include "../Mesh.h"
#include "../CubeTexture.h"

enum class BlockType
{
	TOP_GRASS,
};

class Block
{
public:
	Block(BlockType blockType, glm::vec3 position);
	~Block();

	void setTexture(CubeTexture* texture);

	Mesh* mesh;
};

