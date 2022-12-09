#pragma once

namespace CU = CommonUtilities;

// TODO: Store renderer here?? Set Icon...
// Proccess window events??
// glfwGetPrimaryMonitor() for fullscreen...
// https://www.youtube.com/watch?v=0U-9ofLB22E&t=1s
class Window
{
public:
	Window();
	~Window();

	//void		Draw()		const; - or use this (Have a reference in tihs class for current Renderer???)
	bool							Init();
	void							SetKeyCallback(GLFWkeyfun aKeyCallback);
	void							SetSize(const CU::Vector2<unsigned>& aSize);
	void							SetIcon(const std::string& aPath);
	void							Close();

	void							PollEvents()	const;
	void							BeginDraw()		const;
	void							EndDraw()		const;
	bool							IsOpen()		const;
	const CU::Vector2<unsigned>&	GetSize()		const;

private:
	void							LoadData();
	bool							InitGlfw()		const;

	CU::Vector2<unsigned>			m_size;
	std::string						m_name, m_icon;
	GLFWwindow*						m_window;
};