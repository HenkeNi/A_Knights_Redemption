#pragma once
#include "DataTypes/Structs.h"

class Window;
class Camera;

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Init();
	void Shutdown();

	void DrawSprite();
	void DrawQuad();

	void BeginFrame();
	void Display();
	void EndFrame();

private:
	Window*			m_window;
	Camera*			m_camera;
	RenderContext	m_quadContext;
	RenderStats		m_stats;
};

