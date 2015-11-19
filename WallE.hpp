#ifndef WALLE_HPP
#define WALLE_HPP

#include <string>
#include "Stack.hpp"

class Labyrinth;
class Square;

/// <summary>
/// Classe représentant un robot pouvant trouver un chemin dans un labyrinthe.
/// </summary>
class WallE final
{
    public:
        WallE();
        ~WallE();		
        void Explore(const Labyrinth* labyrinth);		
        std::string GetSolution()const;
    private:
        Square* currentSquare;
        Stack<Square> pathStartToExit;
};

#endif // WALLE_HPP
