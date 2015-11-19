#include "ConsoleMenu.h"
#include <cctype>
#include <iostream>
#include <limits>
#include "Labyrinth.h"
#include "WallE.hpp"

using namespace std;
/// <summary>
/// Initializes a new instance of the <see cref="ConsoleMenu"/> class.
/// </summary>
ConsoleMenu::ConsoleMenu()
{
}

/// <summary>
/// Finalizes an instance of the <see cref="ConsoleMenu"/> class.
/// </summary>
ConsoleMenu::~ConsoleMenu()
{
}

/// <summary>
/// Runs this instance.
/// </summary>
void ConsoleMenu::Run()
{
	DisplayCredits();
	std::cin.get();
	char input;
	char tabValidInputs[] = { 'V', 'v', 'S', 's', 'Q', 'q' };
	const int NB_ELEMENTS = 6;
	do
	{
		system("cls");
		input = ReadValidInput(tabValidInputs, NB_ELEMENTS);
	}
	while (ManageSelection(input));
}

/// <summary>
/// Affiche les credits.
/// </summary>
void ConsoleMenu::DisplayCredits()
{
	cout << "****************************" << endl;
	cout << "*    Travail pratique 2    *" << endl;
	cout << "****************************" << endl;
}

/// <summary>
/// Affiche le menu.
/// </summary>
void ConsoleMenu::DisplayMenu()
{
	cout << "Visualiser (v)\nSolution (s)\nQuitter (q)" << endl;
}

/// <summary>
/// Gère les opérations à faire selon la sélection.
/// </summary>
/// <param name="input">L'input sélectionné.</param>
/// <returns>Valeur bool si on quitte</returns>
bool ConsoleMenu::ManageSelection(char input)
{
	string mapToStr; // La map en string
	string fileName = "labyrinthe_exemple1.txt"; // Le nom du fichier texte
	Labyrinth laby(fileName);
	WallE wallE;
	bool quit = false;

	switch (input)
	{
		case'v':
			mapToStr = laby.ToString();
			cout << mapToStr;
			break;
		case's':
		    wallE.Explore(&laby);
		    std::cout << wallE.GetSolution() << std::endl;
			break;
		case'q':
			quit = true;
			break;
		case'i':
			cout << "Caractere invalide" << endl;
			break;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
	return !quit;
}

/// <summary>
/// Lit l'input valide.
/// </summary>
/// <param name="tabValidInputs">Le tableau d'inputs valides.</param>
/// <param name="nbElements">le nb d'éléments.</param>
/// <returns>L'input valide en minuscule ou i si invalide</returns>
char ConsoleMenu::ReadValidInput(char tabValidInputs[], int nbElements)
{
	DisplayMenu();
	char userInput;
	cin >> userInput;
	for (int i = 0; i < nbElements; i++)
	{
		if (tabValidInputs[i] == userInput)
		{
			if (i % 2 == 0)
			{
				return std::tolower(userInput);
			}
			return userInput;
		}
	}
	return 'i';
}
