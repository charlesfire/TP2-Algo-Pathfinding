#include <fstream>
#include "Labyrinth.h"
#include "Square.h"

using namespace std;

Labyrinth::Labyrinth(const std::string& fileName)
{
	string raw; //string qui contiendra la ligne brut
	ifstream streamInput;
	streamInput.open(fileName);
	if (!streamInput)
	{
		string exceptionCaption = "Le fichier " + fileName + " n'existe pas.";
		throw invalid_argument(exceptionCaption);
	}
	////……
	int y = 0;
	while (streamInput && y < 20)
	{
		getline(streamInput, raw);
		string currentLine;

		for (size_t i = 0; i < raw.size(); ++i) //On élimine les impuretés du fichier (c’est possible) et on travaillera avec currentLine 
		{
			if (raw[i] != '\0')
			{
				currentLine += raw[i];
			}
		}
		//ici faut faire de quoi pour donner une valeur aux square autour
		y++;
	}
	startSquare = tabSquare[0][0];
	streamInput.clear();
	//……
	streamInput.close();
}


Labyrinth::~Labyrinth()
{
}


std::string Labyrinth::ToString()
{

}


Square* Labyrinth::GetStartSquare()
{
	return startSquare;
}
