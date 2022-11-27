#include "Pch.h"
#include "Game.h"


int main()
{
	Game game;

    if (!game.Init())
        return -1;
  
	while (game.IsRunning())
	{
		game.ProcessInput();
		game.Update();
		game.LateUpdate();
		game.Draw();
	}

	game.Shutdown();
	return 0;
}