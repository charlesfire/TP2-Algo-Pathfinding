#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H

#include <iostream>

class ConsoleMenu
{
    public:
        ConsoleMenu();
        ~ConsoleMenu();
    private:
        char ReadValidInput(char tabValidInputs[], int nbElements);
        void ClearScreen()const;
        void DisplayMenu();
        void DisplayCredits();
        bool ManageSelection(char input);
    public:
        void Run();
};

#endif // CONSOLEMENU_H
