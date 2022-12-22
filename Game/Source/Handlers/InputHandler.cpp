#include "Pch.h"
#include "InputHandler.h"
#include "Dispatcher/Dispatcher.h"
#include "Events/Event.h"


InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

void InputHandler::Init()
{
	//glfwSetKeyCallback(aWindow, KeyCallback);
}

void InputHandler::KeyCallback(GLFWwindow* aWindow, int aKey, int aScanCode, int anAction, int someMods)
{
	if (aKey == GLFW_KEY_E)
	{
		if (anAction == GLFW_PRESS)
			;
			//Dispatcher::GetInstance().SendEvent({ eEventType::KeyPressed, true });
			//std::cout << "Press e";
		else if (anAction == GLFW_REPEAT)
			std::cout << "Repeat e";
		else if (anAction == GLFW_RELEASE)
			std::cout << "Release e";
	}
}