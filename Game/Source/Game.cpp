#include "Pch.h"
#include "Game.h"


Game::Game()
{

}

Game::~Game()
{

}

bool Game::Init()
{
	if (!glfwInit())			return false;
	if (!m_window.Init())		return false; 
	if (glewInit() != GLEW_OK)	return false; 

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	RegisterScenes();
	MapControlls();
}

void Game::ProcessInput()
{
	glfwPollEvents(); 
}

void Game::Update()
{
	std::cout << "Update\n";
}

void Game::LateUpdate()
{
	std::cout << "LateUpdate\n";
}

void Game::Draw()
{
	m_window.Draw();
}

void Game::Shutdown()
{
	glfwTerminate();
}

bool Game::IsRunning() const
{
	return m_window.IsOpen();
}

void Game::RegisterScenes()
{

}

void Game::MapControlls()
{

}