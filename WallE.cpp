#include "WallE.hpp"
#include <algorithm>
#include <array>
#include <sstream>
#include "Labyrinth.h"
#include "Square.h"

WallE::WallE() : currentSquare(nullptr), pathStartToExit()
{
	//ctor
}

WallE::~WallE()
{
	// Tant que le chemin parcouru contient encore des cases...
	while (pathStartToExit.Top())
	{
		// On restaure la case à son état initial.
		pathStartToExit.Top()->visited = false;

		//On retire la case.
		pathStartToExit.Pop();
	}
}

/// <summary>
/// Explore un labyrinthe et trouve une solution valide.
/// </summary>
/// <param name="labyrinth">Le labyrinthe à explorer.</param>
void WallE::Explore(const Labyrinth* labyrinth)
{	
	// On ajoute la case de départ à la solution.
	pathStartToExit.Push(labyrinth->GetStartSquare());

	// Tant que la case actuelle n'est pas la sortie...
	while (pathStartToExit.Top()->value != 'S')
	{
		// Si la case en bas de la case actuelle n'est pas un mur et qu'on ne l'as pas encore visité...
		if (pathStartToExit.Top()->lowerSquare->value != 'X' && !(pathStartToExit.Top()->lowerSquare->visited))
			pathStartToExit.Push(pathStartToExit.Top()->lowerSquare); // On ajoute la case au chemin.
		// Sinon si la case à droite de la case actuelle n'est pas un mur et qu'on ne l'as pas encore visité...
		else if (pathStartToExit.Top()->rightSquare->value != 'X' && !(pathStartToExit.Top()->rightSquare->visited))
			pathStartToExit.Push(pathStartToExit.Top()->rightSquare); // On ajoute la case au chemin.
		// Sinon si la case à gauche de la case actuelle n'est pas un mur et qu'on ne l'as pas encore visité...
		else if (pathStartToExit.Top()->leftSquare->value != 'X' && !(pathStartToExit.Top()->leftSquare->visited))
			pathStartToExit.Push(pathStartToExit.Top()->leftSquare); // On ajoute la case au chemin.
		// Sinon si la case en haut de la case actuelle n'est pas un mur et qu'on ne l'as pas encore visité...
		else if (pathStartToExit.Top()->upperSquare->value == 'X' && !(pathStartToExit.Top()->upperSquare->visited))
			pathStartToExit.Push(pathStartToExit.Top()->upperSquare); // On ajoute la case au chemin.
		else // Culs-de-sac
			pathStartToExit.Pop(); // On retire la dernière case ajoutée

		// Si le chemin ne comporte aucune case...
		if (pathStartToExit.IsEmpty())
			break; // Il n'y a aucune solution, donc on quitte la boucle.

		// On marque la case visité comme étant visité.
		pathStartToExit.Top()->visited = true;
	}
}

/// <summary>
/// Obtient une représentation textuelle de la solution.
/// </summary>
/// <returns>Retourne une représentation textuelle de la solution.</returns>
std::string WallE::GetSolution()const
{
	return pathStartToExit.ToReverseString();
}
