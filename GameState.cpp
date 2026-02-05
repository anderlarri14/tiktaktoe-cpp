#include "GameState.h"

GameState::GameState()
	: isGameOver{ false }
	, currentPlayer{ Player() }
	, winner{ Player() }
{
	std::cout << "GameState initialized." << std::endl;
}