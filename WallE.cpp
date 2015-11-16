#include "WallE.hpp"
#include <sstream>
#include "Labyrinth.h"
#include "Square.h"

WallE::WallE() : currentSquare(nullptr), pathStartToExit()
{
    //ctor
}

void WallE::Explore(const Labyrinth* labyrinth)
{
    pathStartToExit.Push(labyrinth->GetStartSquare());
    while (pathStartToExit.Top()->value != 'S')
    {
        if (!(pathStartToExit.Top()->lowerSquare->value == 'X') && !(pathStartToExit.Top()->lowerSquare->visited))
            pathStartToExit.Push(pathStartToExit.Top()->lowerSquare);
        else if (!(pathStartToExit.Top()->rightSquare->value == 'X') && !(pathStartToExit.Top()->rightSquare->visited))
            pathStartToExit.Push(pathStartToExit.Top()->rightSquare);
        else if (!(pathStartToExit.Top()->leftSquare->value == 'X') && !(pathStartToExit.Top()->leftSquare->visited))
            pathStartToExit.Push(pathStartToExit.Top()->leftSquare);
        else if (!(pathStartToExit.Top()->upperSquare->value == 'X') && !(pathStartToExit.Top()->upperSquare->visited))
            pathStartToExit.Push(pathStartToExit.Top()->upperSquare);
        else
            pathStartToExit.Pop();
        pathStartToExit.Top()->visited = true;
    }
}

std::string WallE::GetSolution()
{
    std::stringstream solution;
    pathStartToExit.Top();
    while (pathStartToExit.Top() != nullptr)
    {
        solution << "(" << pathStartToExit.Top()->x << ", " << pathStartToExit.Top()->y << ")" << std::endl;
        pathStartToExit.Pop();
    }

    return solution.str();
}
