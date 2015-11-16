#include "ConsoleMenu.h"
#include <cctype>
#include <iostream>
#include <limits>
#include "Labyrinth.h"
#include "WallE.hpp"

using namespace std;

ConsoleMenu::ConsoleMenu()
{
}


ConsoleMenu::~ConsoleMenu()
{
}


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


void ConsoleMenu::DisplayCredits()
{
	cout << "****************************" << endl;
	cout << "*    Travail pratique 2    *" << endl;
	cout << "****************************" << endl;
}


void ConsoleMenu::DisplayMenu()
{
	cout << "Visualiser (v)\nSolution (s)\nQuitter (q)" << endl;
}


bool ConsoleMenu::ManageSelection(char input)
{

	string mapToStr;
	string fileName = "labyrinthe_exemple.txt";
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
			cout << "Caractère invalide" << endl;
			break;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
	return !quit;
}


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
