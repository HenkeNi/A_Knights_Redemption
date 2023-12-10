#include "Pch.h"
#include "InputHandler.h"
#include "Dispatcher/Dispatcher.h"
#include "Events/Event.h"


std::unordered_map<eInput, eKeyStatus> InputHandler::m_keyStatus;

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

void InputHandler::Init(Window* aWindow)
{
	m_window = aWindow;
	//glfwSetKeyCallback(aWindow, KeyCallback);
}

void InputHandler::ProcessInput()
{
	for (auto& status : m_keyStatus)
	{
		TranslateInputToEvent(status.first, 1.f); // Pass along if pressed or released???
	}
}

void InputHandler::MapEvent(eInput anInput, eEventType aType)
{
	m_events[anInput] = aType;

}

void InputHandler::KeyCallback(GLFWwindow* aWindow, int aKey, int aScanCode, int anAction, int someMods)
{
	switch (aKey)
	{
	case GLFW_KEY_W:
		m_keyStatus[eInput::Key_W] = GetKeyStatus(anAction);
		break;
	case GLFW_KEY_A:
		m_keyStatus[eInput::Key_A] = GetKeyStatus(anAction);
		break;
	case GLFW_KEY_S:
		m_keyStatus[eInput::Key_S] = GetKeyStatus(anAction);
		break;
	case GLFW_KEY_D:
		m_keyStatus[eInput::Key_D] = GetKeyStatus(anAction);
		break;
	case GLFW_KEY_SPACE:
		m_keyStatus[eInput::Key_Space] = GetKeyStatus(anAction);
		break;
	case GLFW_KEY_ESCAPE:
		m_keyStatus[eInput::Key_Escape] = GetKeyStatus(anAction);
		break;
	}
}

eKeyStatus InputHandler::GetKeyStatus(int anAction)
{
	switch (anAction)
	{
	case GLFW_PRESS:
		return eKeyStatus::Pressed;
	case GLFW_REPEAT:
		return eKeyStatus::Held;
	case GLFW_RELEASE:
		return eKeyStatus::Released;
	}
}

void InputHandler::TranslateInputToEvent(eInput anInput, float aValue)
{
	if (IsEventMapped(anInput))
	{
		Dispatcher::GetInstance().SendEvent(Event{ m_events[anInput], aValue });
	}
}

bool InputHandler::IsKeyPressed(eInput anInput)
{
	bool isPressed = m_keyStatus[anInput] == eKeyStatus::Pressed;
	return isPressed;
}


bool InputHandler::IsEventMapped(eInput anInput) const
{
	return m_events.find(anInput) != m_events.end();

}

