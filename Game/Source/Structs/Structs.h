#pragma once
#include "SceneManager/SceneManager.h"
#include "Window/Window.h"


struct SharedContext
{
	Window&			m_window;
	SceneManager&	m_sceneManager;
};