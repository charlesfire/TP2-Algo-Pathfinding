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
	return ' ';
}


void ConsoleMenu::DisplayMenu()
{
}


void ConsoleMenu::DisplayCredits()
{
	cout << "****************************/n**/n****************************";
}


bool ConsoleMenu::ManageSelection(char input)
{
	switch (input)
	{
	case'v':
		;
	case's':
		;
	case'q':
		;
	}
	return false;
}

void ConsoleMenu::Run()
{
	char input;
	char tabValidInputs[] = { 'V', 'v', 'S', 's', 'Q', 'q' };
	const int NB_ELEMENTS = 6;
	do
	{
		system("cls");
		input = ReadValidInput(tabValidInputs, NB_ELEMENTS);
	} while (ManageSelection(input));
}