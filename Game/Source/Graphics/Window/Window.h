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

	bool							Init();
	void							SetKeyCallback(GLFWkeyfun aKeyCallback);
	void							SetSize(const CU::Vector2<unsigned>& aSize);
	void							SetIcon(const std::string& aPath);
	void							Close();

	void							PollEvents()	const;
	void							ClearScreen()	const;
	void							SwapBuffers()	const;
	bool							IsOpen()		const;
	const CU::Vector2<unsigned>&	GetSize()		const;

	void			SetTitle(const std::string& aTitle);

private:
	bool							InitGlfw()		const;
	void							LoadData();

	CU::Vector2<unsigned>			m_size;
	std::string						m_name, m_icon;
	GLFWwindow*						m_window;
};