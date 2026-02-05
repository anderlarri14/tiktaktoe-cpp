#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <iostream>

#include "Player.h"

class GameState
{
private:
	bool isGameOver;
	Player currentPlayer;
	Player winner;

public:
	GameState();

};



#endif