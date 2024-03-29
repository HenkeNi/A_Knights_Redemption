#include "Pch.h"
#include "Window.h"
#include "Dispatcher/Dispatcher.h"
#include "Events/Event.h"

void FrameBufferSizeCallback(GLFWwindow* aWindow, int aWidth, int aHeight);
void WindowFocusCallback(GLFWwindow* aWindow, int aFocused);


Window::Window()
	: m_window{ nullptr }, m_size{ 800, 600 }, m_name{ "A Knights Redemption" }
{
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::Init()
{
	InitGlfw(); 
	LoadData();

	m_window = glfwCreateWindow(m_size.x, m_size.y, m_name.c_str(), nullptr, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, FrameBufferSizeCallback); 
	glfwSetWindowFocusCallback(m_window, WindowFocusCallback);
	
	glViewport(0, 0, m_size.x, m_size.y);
	SetIcon(m_icon);
	
	return true;
}

void Window::SetKeyCallback(GLFWkeyfun aKeyCallback)
{
	glfwSetKeyCallback(m_window, aKeyCallback);
}

void Window::SetSize(const CU::Vector2<unsigned>& aSize)
{
	glfwSetWindowSize(m_window, aSize.x, aSize.y);
}

void Window::SetIcon(const std::string& aPath)
{
	GLFWimage image;
	image.pixels = stbi_load(aPath.c_str(), &image.width, &image.height, 0, 4);

	glfwSetWindowIcon(m_window, 1, &image);
	stbi_image_free(image.pixels);
}

void Window::Close()
{
	glfwSetWindowShouldClose(m_window, true);
}

void Window::PollEvents()	const
{
	glfwPollEvents();
}

void Window::ClearScreen() const
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::SwapBuffers() const
{
	glfwSwapBuffers(m_window);
}

bool Window::IsOpen() const
{
	return !glfwWindowShouldClose(m_window);
}

const CU::Vector2<unsigned>& Window::GetSize() const
{
	return m_size;
}

void Window::SetTitle(const std::string& aTitle)
{
	glfwSetWindowTitle(m_window, aTitle.c_str());
}

bool Window::InitGlfw()	const
{
	if (!glfwInit())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	return true;
}

void Window::LoadData()
{
	std::ifstream ifs{ "../Assets/JSON/WindowSettings.json" };
	std::string content{ std::istreambuf_iterator<char>(ifs), (std::istreambuf_iterator<char>()) };

	rapidjson::Document document;
	if (!document.Parse(content.c_str()).HasParseError())
	{
		m_name	 = document["window"]["name"].GetString();
		m_icon	 = document["window"]["icon"].GetString();
		m_size.x = document["window"]["size"]["width"].GetInt();
		m_size.y = document["window"]["size"]["height"].GetInt();
	}
}

#pragma region CALLBACK_FUNCTIONS

void FrameBufferSizeCallback(GLFWwindow* aWindow, int aWidth, int aHeight)
{
	glViewport(0, 0, aWidth, aHeight);
}

void WindowFocusCallback(GLFWwindow* aWindow, int aFocused)
{
	Dispatcher::GetInstance().SendEvent(Event{ aFocused ? eEventType::WindowGainedFocus : eEventType::WindowLostFocus, nullptr });
}

#pragma endregion CALLBACK_FUNCTIONS