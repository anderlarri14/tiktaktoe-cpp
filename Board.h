#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>

#include "Player.h"
#include "GameState.h"

class Board
{
private:
	std::vector<std::vector<char>> grid;

public:
	Board();
	bool isPositionValid(std::vector<int>&cell);
	void makeMove(std::vector<int>& cell, Player& currentPlayer);
	void drawBoard(GameState& state);

	std::vector<std::vector<char>>& getGrid() { return grid; };
	void setGrid(std::vector<std::vector<char>>& grid) { this->grid = grid; };
};

#endif