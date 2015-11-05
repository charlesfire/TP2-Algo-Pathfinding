#pragma once
#include <string>
#include "Square.h"
class Labyrinth final
{
public:
	Labyrinth();
	~Labyrinth();
	std::string	ToString();
	Square* GetStartSquare();
private:
	Square* startSquare;
	Square* tabSquare[20][20];
};

