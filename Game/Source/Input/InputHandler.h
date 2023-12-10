#pragma once
#include "DataTypes/Enumerations.h"

class Window;

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void				Init(Window* aWindow);
	void				ProcessInput();
	void				MapEvent(eInput anInput, eEventType aType);

	static void			KeyCallback(GLFWwindow* aWindow, int aKey, int aScanCode, int anAction, int someMods);
	static eKeyStatus	GetKeyStatus(int anAction);

	bool				IsKeyPressed(eInput anInput);

private:
	void				TranslateInputToEvent(eInput anInput, float aValue = 1.0f);
	bool				IsEventMapped(eInput anInput)										const;


	static std::unordered_map<eInput, eKeyStatus>	m_keyStatus; // Renaem s_keyStatus?

	std::unordered_map<eInput, eEventType>			m_events;
	Window*											m_window;

	// bool keysDown[eKeys::Count], keysPressed[eKeys::Count]


	// std::unordered_map<Command, eInput> m_commands;

};

