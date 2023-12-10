#include "Pch.h"
#include "Game.h"


int main()
{
	Game game;

	if (!game.Init())
        return -1;
  
	game.GameLoop();
	game.Shutdown();

	return 0;
}