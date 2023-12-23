#include "Window.h"
#include "Renderer.h"

#include "LightSource.h"
#include "game/Block.h"
#include "game/BlockManager.h"

int main()
{
	Window window(1920, 1080, "Not another minecraft clone!");

	Renderer renderer(&window);

	BlockManager blockManager;
	renderer.init();

	int x = 0;
	int y = 0;

	while (y < 20)
	{
		renderer.blockManager.addBlock(BlockType::TOP_GRASS, glm::vec3((float)x, 0.0f, float(y)));
		x++;

		if (x > 20)
		{
			x = 0;
			y++;
		}
	}

	LightSource lightSource;
	//lightSource.mesh->rotate(45.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	lightSource.mesh->translate(glm::vec3(-1.0f, 1.0f, 1.0f));
	//lightSource.color = glm::vec4(0.6f, 0.2f, 0.1f, 1.0f);

	//renderer.addLightSource(lightSource);

	renderer.enterGameLoop();

	return 0;
}