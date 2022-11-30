#pragma once

namespace CU = CommonUtilities;

class Window
{
public:
	Window();


	bool		Init();
	void		Close();
	// Proccess window events??
	void		Draw()		const;
	bool		IsOpen()	const;
	GLFWwindow* GetWindow();
private:
	void		LoadData();

	unsigned	m_width, m_height;
	std::string m_name;
	GLFWwindow* m_window;
};