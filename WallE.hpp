#ifndef WALLE_HPP
#define WALLE_HPP

#include <string>
#include "Stack.hpp"

class Labyrinth;
class Square;

class WallE final
{
    public:
        WallE();
        ~WallE() = default;
        void Explore(const Labyrinth* labyrinth);
        std::string GetSolution();
    private:
        Square* currentSquare;
        Stack<Square> pathStartToExit;
};

#endif // WALLE_HPP
