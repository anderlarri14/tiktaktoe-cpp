#include "Board.h"

Board::Board()
	: grid{ std::vector<std::vector<char>>(3, std::vector<char>(3, ' '))}
{
	std::cout << "Board initialized." << std::endl;
}

bool Board::isPositionValid(std::vector<int> &cell)
{
	if (cell[0] < 0 || cell[0] > 2 || cell[1] < 0 || cell[1] > 2)
	{
		return false;
	}

	if (grid[cell[0]][cell[1]] != ' ')
	{
		return false;
	}

	return true;
}

void Board::makeMove(std::vector<int>& cell, Player &currentPlayer)
{
	grid[cell[0]][cell[1]] = currentPlayer.getSymbol();
}

void Board::drawBoard(GameState &state)
{
	std::cout << "-----------" << std::endl;
	std::cout << "| NEW TURN|" << std::endl;
	std::cout << "-----------" << std::endl;

	std::cout << state.getCurrentPlayer().getName() << "'s turn, playing with: "
		      << state.getCurrentPlayer().getSymbol() << std::endl;


	std::cout << "-------------" << std::endl;
	for (int i = 0; i < grid.size(); i++)
	{
		std::cout << "|";
		for (int j = 0; j < grid[0].size(); j++)
		{
			std::cout << " " << grid[i][j] << " ";
			std::cout << "|";
		}
		std::cout << std::endl;
		std::cout << "-------------" << std::endl;
	}
}