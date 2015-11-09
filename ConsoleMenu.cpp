#include "ConsoleMenu.h"
#include "Labyrinth.h"
#include "WallE.hpp"
#include <cctype>
#include <iostream>

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
	} while (ManageSelection(input));
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
	Labyrinth* laby = new Labyrinth(fileName);

	switch (input)
	{
		case'v':
		{
			mapToStr = laby->ToString();
			cout << mapToStr;
			std::cin.get(); 
			delete laby;
			return true;
		}
		case's':
		{
			delete laby;
			std::cin.get();
			return true;
		}
		case'q':
		{
			delete laby;
			std::cin.get();
			return false;
		}

		case'i':
		{
			delete laby;
			cout << "Caractère invalide" << endl;
			std::cin.get();
			return true;
		}
	}
	return false;
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