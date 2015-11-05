//#include "stdafx.h"
#include "ConsoleMenu.h"
#include <iostream>

using namespace std;

ConsoleMenu::ConsoleMenu()
{
}


ConsoleMenu::~ConsoleMenu()
{
}

void ConsoleMenu::ClearScreen()const
{
    std::cout << string(3000, '\n');
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
				return _tolower(userInput);
			}
			return userInput;
		}
	}
	return 'i';
}


void ConsoleMenu::DisplayMenu()
{
	//cout << "Visualiser (v)\nSolution (s)\nQuitter (q)" << endl;
}


void ConsoleMenu::DisplayCredits()
{
	cout << "****************************\n*    Travail pratique   *\n****************************" << endl;
}


bool ConsoleMenu::ManageSelection(char input)
{
	string mapToStr;
	string fileName;

	switch (input)
	{
        case'v':
        {

            std::cin.get();
            return true;
        }
        case's':
        {

            std::cin.get();
            return true;
        }
        case'q':
        {
            cout << "A +." << endl;
            std::cin.get();
            return false;
        }

        case'i':
        {
            cout << "Caractere invalide" << endl;
            std::cin.get();
            return true;
        }
	}
	return false;
}


void ConsoleMenu::Run()
{
	DisplayCredits();
	std::cin.get();
	ClearScreen();

	char input;
	char tabValidInputs[] = { 'V', 'v', 'S', 's', 'Q', 'q' };
	const int NB_ELEMENTS = 6;
	do
	{
		input = ReadValidInput(tabValidInputs, NB_ELEMENTS);
	}
	while(ManageSelection(input));
}
