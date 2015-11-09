#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <string>

class Square;

class Labyrinth final
{
	public:
		Labyrinth(const std::string& fileName);
		~Labyrinth();
		std::string& ToString()const;
		Square* GetStartSquare()const;
	private:
		Square* startSquare;
		Square* tabSquare[20][20];
};

#endif // LABYRINTH_H
