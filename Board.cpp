#include "Board.h"

Board::Board()
	: grid{ std::vector<std::vector<char>>(3, std::vector<char>(' '))}
{
	std::cout << "Board initialized." << std::endl;
}