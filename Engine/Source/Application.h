#pragma once


namespace Engine
{
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;


		void Init();
		void ProcessInput();
		void Update();
		void LateUpdate();
		void Draw();
		void Shutdown();
		bool IsRunning() const;

		//virtual Application* CreateApplication() = 0;
		//static Application* CreateApplication() = 0;
	};

	// Make virtual member?
	Application* CreateApplication();
}