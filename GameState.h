#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <iostream>
//#include <vector>

#include "Player.h"

class GameState
{
private:
	bool isGameOver;
	Player currentPlayer;
	Player winner;

public:
	GameState();
	//void checkWinner(std::vector<std::vector<char>>& grid, Player& playerA, Player& playerB);

	bool getIsGameOver() { return isGameOver; };
	void setIsGameOver(bool isGameOver) { this->isGameOver = isGameOver; };

	Player& getCurrentPlayer() { return currentPlayer; };
	void setCurrentPlayer(Player &currentPlayer) { this->currentPlayer = currentPlayer; };

	Player& getWinner() { return winner; };
	void setWinner(Player& winner);
};



#endif