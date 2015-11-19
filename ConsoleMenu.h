#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H

#include <iostream>
#include "mld.hpp"
//G�re l'affichage du menu
class ConsoleMenu
{
	public:
		ConsoleMenu();
		~ConsoleMenu();
		void Run();
	private:
	    void ClearScreen()const;
		void DisplayCredits();
		void DisplayMenu();
		bool ManageSelection(char input);
		char ReadValidInput(char tabValidInputs[], int nbElements);
};

#endif // CONSOLEMENU_H
