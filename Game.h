#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "Board.h"
#include "GameState.h"
#include "Player.h"

class Game
{
private:
	Board board;
	Player playerA;
	Player playerB;
	GameState state;

	void setupGame();
	void askForInput(std::vector<int> &cell);
	void changeTurn();
	void checkWinner();
	void setWinner(char s);

public:
	Game();
	void Start();


};

#endif