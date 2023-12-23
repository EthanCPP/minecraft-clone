#include "Camera.h"

Camera::Camera(int viewportWidth, int viewportHeight, glm::vec3 position)
{
	this->viewportWidth = viewportWidth;
	this->viewportHeight = viewportHeight;
	this->position = position;
}

Camera::~Camera()
{

}

void Camera::init(float fov, float nearPlane, float farPlane)
{
	this->fov = fov;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
}

void Camera::matrix(Shader& shader, const char* uniform)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	view = glm::lookAt(this->position, this->position + this->orientation, this->up);
	proj = glm::perspective(glm::radians(this->fov), (float)this->viewportWidth / this->viewportHeight, this->nearPlane, this->farPlane);

	// export matrix to the shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(proj * view));
}

void Camera::setPosition(glm::vec3 position)
{
	this->position = position;
}

void Camera::setFov(float fov)
{
	this->fov = fov;
}

void Camera::setNearPlane(float nearPlane)
{
	this->nearPlane = nearPlane;
}

void Camera::setFarPlane(float farPlane)
{
	this->farPlane = farPlane;
}

glm::vec3 Camera::getPosition()
{
	return this->position;
}

void Camera::update(Window* window)
{
	// forward
	if (glfwGetKey(window->glfwWindow, GLFW_KEY_W) == GLFW_PRESS)
	{
		position += (speed * window->dt) * orientation;
	}
	// backward
	else if (glfwGetKey(window->glfwWindow, GLFW_KEY_S) == GLFW_PRESS)
	{
		position += (speed * window->dt) * -orientation;
	}

	// strafe left
	if (glfwGetKey(window->glfwWindow, GLFW_KEY_A) == GLFW_PRESS)
	{
		position += (speed * window->dt) * -glm::normalize(glm::cross(orientation, up));
	}
	// strafe right
	else if (glfwGetKey(window->glfwWindow, GLFW_KEY_D) == GLFW_PRESS)
	{
		position += (speed * window->dt) * glm::normalize(glm::cross(orientation, up));
	}

	// up
	if (glfwGetKey(window->glfwWindow, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		position += (speed * window->dt) * up;
	}
	// down
	else if (glfwGetKey(window->glfwWindow, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		position += (speed * window->dt) * -up;
	}

	// mouse inputs
	if (glfwGetMouseButton(window->glfwWindow, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		// hide cursor
		glfwSetInputMode(window->glfwWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick)
		{
			glfwSetCursorPos(window->glfwWindow, (window->width / 2), (window->height / 2));
			firstClick = false;
		}

		double mouseX, mouseY;
		glfwGetCursorPos(window->glfwWindow, &mouseX, &mouseY);

		float rotX = (sensitivity * window->dt) * (float)(mouseY - (window->height / 2)) / window->height;
		float rotY = (sensitivity * window->dt) * (float)(mouseX - (window->width / 2)) / window->width;

		glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up)));

		// check if vertical orientation is legal or not (prevent upside down views)
		if (abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			orientation = newOrientation;
		}

		orientation = glm::rotate(orientation, glm::radians(-rotY), up);

		glfwSetCursorPos(window->glfwWindow, (window->width / 2), (window->height / 2));
	}
	else if (glfwGetMouseButton(window->glfwWindow, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		// show cursor
		glfwSetInputMode(window->glfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

		firstClick = true;
	}
}