#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <string>
//#include "Square.h"

class Square;

class Labyrinth final
{
	public:
		Labyrinth(const std::string& fileName);
		~Labyrinth();
		std::string	ToString();
		Square* GetStartSquare();
	private:
		Square* startSquare;
		Square* tabSquare[20][20];
};

#endif // LABYRINTH_H
