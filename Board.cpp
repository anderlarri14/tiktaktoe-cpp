#include "Board.h"

Board::Board()
	: grid{ std::vector<std::vector<char>>(3, std::vector<char>(3, ' '))}
{
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
	std::cout << "| NEW TURN |" << std::endl;
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

bool Board::endGame(GameState &state)
{
	std::cout << "-----------------" << std::endl;
	std::cout << "| GAME FINISHED |" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << std::endl;
	std::cout << "The winner or result was: " << state.getWinner().getName() << std::endl;
	std::cout << std::endl;
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

	char playAnother = ' ';
	while (playAnother != 'Y' && playAnother != 'N')
	{
		std::cout << "Do you want to play another game? (Y/N)" << std::endl;
		std::cin >> playAnother;
		playAnother = toupper(playAnother);

		if (playAnother != 'Y' && playAnother != 'N')
		{
			std::cout << "Invalid input. Please enter 'Y' or 'N'." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	}
	return playAnother == 'Y';
}

void Board::resetBoard()
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			grid[i][j] = ' ';
		}
	}
}