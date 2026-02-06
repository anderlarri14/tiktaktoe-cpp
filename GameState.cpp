#include "GameState.h"

GameState::GameState()
	: isGameOver{ false }
	, currentPlayer{ Player() }
	, winner{ Player() }
{
	std::cout << "GameState initialized." << std::endl;
}

void GameState::setWinner(Player& winner) {
	this->winner = winner;
    this->isGameOver = true;
}