#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <string>

class Square;
//La map du labyrinth
class Labyrinth final
{
	public:
		Labyrinth(const std::string& fileName);
		~Labyrinth();		
		std::string ToString()const;
		Square* GetStartSquare()const;
	private:
		Square* startSquare; // Le Square de début(valeur char=d)
		Square* tabSquare[20][20]; // Tableau de Squares
};

#endif // LABYRINTH_H
