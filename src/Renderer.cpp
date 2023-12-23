#include "Renderer.h"
#include <iostream>

Renderer::Renderer(Window* window) :
	defaultShader("default.vert", "default.frag"),
	dullShader("dull.vert", "dull.frag"),
	camera(window->width, window->height, glm::vec3(0.0f, 0.0f, 2.0f)),
	blockManager()
{
	this->window = window;
}

Renderer::~Renderer()
{

}

void Renderer::init()
{
	camera.init(45.0f, 0.1f, 100.0f);

	blockManager.init();
}

void Renderer::setRefreshColor(glm::vec4 refreshColor)
{
	this->refreshColor = refreshColor;
}

void Renderer::addMesh(Mesh& mesh)
{
	mesh.prepareTexture(this->getShader(mesh.meshType));
	meshes.push_back(&mesh);
}

void Renderer::addLightSource(LightSource& lightSource)
{
	this->addMesh(*lightSource.mesh);
	lightSources.push_back(&lightSource);
}

void Renderer::draw()
{
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		camera.matrix(this->getShader(meshes[i]->meshType), "camMatrix");

		if (meshes[i]->meshType == MeshType::STATIC)
		{
			// just dealing with 1 light source right now
			if (!lightSources.empty()) {
				this->getShader(MeshType::STATIC).activate();

				glUniform4f(glGetUniformLocation(this->getShader(MeshType::STATIC).ID, "lightColor"), lightSources[0]->color.x, lightSources[0]->color.y, lightSources[0]->color.z, lightSources[0]->color.w);
				glUniform3f(glGetUniformLocation(this->getShader(MeshType::STATIC).ID, "lightPos"), lightSources[0]->mesh->getPosition().x, lightSources[0]->mesh->getPosition().y, lightSources[0]->mesh->getPosition().z);
				glUniform3f(glGetUniformLocation(this->getShader(MeshType::STATIC).ID, "camPos"), this->camera.getPosition().x, this->camera.getPosition().y, this->camera.getPosition().z);
			}
		}

		meshes[i]->draw(this->getShader(meshes[i]->meshType));
	}

	blockManager.draw(camera, this->getShader(MeshType::STATIC));
}

Shader& Renderer::getShader(MeshType meshType)
{
	switch (meshType)
	{
	case MeshType::STATIC:
		return defaultShader;
		break;
	case MeshType::LIGHT:
	default:
		return dullShader;
		break;
	}
}

void Renderer::enterGameLoop()
{
	currentFrame = lastFrame = glfwGetTime();

	while (!glfwWindowShouldClose(window->glfwWindow))
	{
		// calculate dt and fps
		currentFrame = glfwGetTime();
		window->dt = (float) currentFrame - lastFrame;
		nbFrames++;
		lastFrame = currentFrame;

		if (currentFrame - lastSecondFrame >= 1.0) 
		{
			window->fps = double(nbFrames) / (currentFrame - lastSecondFrame);
			nbFrames = 0;
			lastSecondFrame = currentFrame;
		}


		glClearColor(refreshColor.x, refreshColor.y, refreshColor.z, refreshColor.w);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->update();
		this->draw();

		glfwSwapBuffers(window->glfwWindow);
		glfwPollEvents();
	}
}

void Renderer::update()
{
	this->camera.update(window);

	std::string windowTitle = "Not another minecraft clone! FPS: " + std::to_string(this->window->fps);

	glfwSetWindowTitle(this->window->glfwWindow, windowTitle.c_str());
}
