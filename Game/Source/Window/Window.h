#pragma once

namespace CU = CommonUtilities;

class Window
{
public:
	Window();


	bool		Init();
	void		Draw()		const;
	bool		IsOpen()	const;

private:
	void		LoadData();

	unsigned	m_width, m_height;
	std::string m_name;
	GLFWwindow* m_window;
};