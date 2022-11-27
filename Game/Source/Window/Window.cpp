#include "Pch.h"
#include "Window.h"


Window::Window()
	: m_window{ nullptr }, m_width{ 800 }, m_height{ 600 }, m_name{ "A Knights Redemption" }
{
	LoadData();
}

bool Window::Init()
{
	m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), nullptr, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		return false;
	}

	glViewport(0, 0, m_width, m_height);
	glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* aWindow, int aWidth, int aHeight) { glViewport(0, 0, aWidth, aHeight); });

	glfwMakeContextCurrent(m_window);
	return true;
}

void Window::Draw() const
{
	glClear(GL_COLOR_BUFFER_BIT);

	// TEST 
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
	//

	/* Swap front and back buffers */
	glfwSwapBuffers(m_window);
}

bool Window::IsOpen() const
{
	return !glfwWindowShouldClose(m_window);
}

void Window::LoadData()
{
	std::ifstream ifs{ "../Assets/JSON/WindowSettings.json" };
	std::string content{ std::istreambuf_iterator<char>(ifs), (std::istreambuf_iterator<char>()) };

	rapidjson::Document document;
	if (!document.Parse(content.c_str()).HasParseError())
	{
		m_name	 = document["window"]["name"].GetString();
		m_width	 = document["window"]["size"]["width"].GetInt();
		m_height = document["window"]["size"]["height"].GetInt();
	}
}