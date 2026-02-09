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

	bool getIsGameOver() { return isGameOver; };
	void setIsGameOver(bool isGameOver) { this->isGameOver = isGameOver; };

	Player& getCurrentPlayer() { return currentPlayer; };
	void setCurrentPlayer(Player &currentPlayer) { this->currentPlayer = currentPlayer; };

	Player& getWinner() { return winner; };
	void setWinner(Player& winner);
};



#endif