#pragma once
//#include "stdafx.h"
#include <iostream>
class ConsoleMenu
{
public:
	ConsoleMenu();
	~ConsoleMenu();
private:
	char ReadValidInput(char tabValidInputs[], int nbElements);
	void DisplayMenu();
	void DisplayCredits();
	bool ManageSelection(char input);
public:
	void Run();
};
