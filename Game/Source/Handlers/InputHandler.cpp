#include "Pch.h"
#include "InputHandler.h"


InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

void InputHandler::Init(GLFWwindow* aWindow)
{
	glfwSetKeyCallback(aWindow, KeyCallback);
}

void InputHandler::KeyCallback(GLFWwindow* aWindow, int aKey, int aScanCode, int anAction, int someMods)
{
	if (aKey == GLFW_KEY_E)
	{
		if (anAction == GLFW_PRESS)
			std::cout << "Press e";
		else if (anAction == GLFW_REPEAT)
			std::cout << "Repeat e";
		else if (anAction == GLFW_RELEASE)
			std::cout << "Release e";
	}
}