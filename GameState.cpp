#include "GameState.h"

GameState::GameState()
	: isGameOver{ false }
	, currentPlayer{ Player() }
	, winner{ Player() }
{
}

void GameState::setWinner(Player& winner) {
	this->winner = winner;
    this->isGameOver = true;
}