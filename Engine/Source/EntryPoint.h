#pragma once
#include "Application.h"

extern Engine::Application* Engine::CreateApplication();

int main()
{
	auto application = Engine::CreateApplication();

	while (application->IsRunning())
	{
		application->ProcessInput();
		application->Update();
		application->LateUpdate();
		application->Draw();
	}

	application->Shutdown();

	delete application;
}