#pragma once

namespace CU = CommonUtilities;

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void		Init();
	void		ProcessInput();
	void		MapEvent();

	static void KeyCallback(GLFWwindow* aWindow, int aKey, int aScanCode, int anAction, int someMods);

private:



	// bool keysDown[eKeys::Count], keysPressed[eKeys::Count]
};

