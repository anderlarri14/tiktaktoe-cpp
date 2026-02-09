#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>


class Player
{
private:
	std::string name;
	char symbol;

public:
	Player();

	const std::string& getName() { return name; };
	void setName(const std::string &name) { this->name = name; };

	const char getSymbol() { return symbol; };
	void setSymbol(char symbol) { this->symbol = symbol; };
};

#endif