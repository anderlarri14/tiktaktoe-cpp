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
	//PREGUNTA He tenido que añadir const para que me acepte directamente un valor "Draw", porque?
	// Tiene que ver con que la variable tiene una direccion de memoria y "Draw" no, entonces la referencia no existe?
	void setName(const std::string &name) { this->name = name; };

	const char getSymbol() { return symbol; };
	void setSymbol(char symbol) { this->symbol = symbol; };
};

#endif