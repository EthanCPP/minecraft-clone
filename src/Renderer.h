#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include "LightSource.h"

#include "game/Block.h"
#include "game/BlockManager.h"

class Renderer
{
public:
	Renderer(Window* window);
	~Renderer();

	void init();

	void setRefreshColor(glm::vec4 refreshColor);
	void enterGameLoop();

	void addMesh(Mesh& mesh);
	void addLightSource(LightSource& lightSource);

	BlockManager blockManager;
private:
	Window* window;

	Shader defaultShader, dullShader;

	glm::vec4 refreshColor = glm::vec4(0.03f, 0.01f, 0.08f, 1.0f);

	std::vector<Mesh*> meshes;
	std::vector<LightSource*> lightSources;

	Camera camera;

private:
	void draw();
	Shader& getShader(MeshType meshType);

	double lastFrame;
	double lastSecondFrame;
	double currentFrame;
	void update();

	int nbFrames = 0;
};

