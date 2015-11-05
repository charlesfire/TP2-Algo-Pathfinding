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
		
		system("pause");
		return true;
	}
	case's':
	{
		
		system("pause");
		return true;
	}
	case'q':
	{
		cout << "A +." << endl;
		system("pause");
		return false;
	}

	case'i':
	{
		cout << "Caractère invalide" << endl;
		system("pause");
		return true;
	}
	}
	return false;
}


void ConsoleMenu::Run()
{
	DisplayCredits();
	system("pause");
	char input;
	char tabValidInputs[] = { 'V', 'v', 'S', 's', 'Q', 'q' };
	const int NB_ELEMENTS = 6;
	do
	{
		system("cls");
		input = ReadValidInput(tabValidInputs, NB_ELEMENTS);
	} while (ManageSelection(input));
}