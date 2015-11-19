#include <fstream>
#include "Labyrinth.h"
#include "Square.h"

using namespace std;

/// <summary>
/// Initializes a new instance of the <see cref="Labyrinth"/> class.
/// </summary>
/// <param name="fileName">Name of the file.</param>
Labyrinth::Labyrinth(const std::string& fileName)
{
	string raw;
	ifstream streamInput;
	streamInput.open(fileName);
	if (!streamInput)
	{
		string exceptionCaption = "Le fichier " + fileName + " n'existe pas.";
		throw invalid_argument(exceptionCaption);
	}
	int y = 0;
	while (streamInput && y < 20)
	{
		getline(streamInput, raw);
		string currentLine;

		for (size_t i = 0; i < raw.size(); ++i)
		{
			if (raw[i] != '\0')
			{
				currentLine += raw[i];
			}
		}
		//On crée 20 squares (une ligne complète)
		for (int x = 0; x < 20; x++)
		{
			tabSquare[x][y] = new Square(x, y, currentLine[x], false);
		}
		y++;
	}

	//On définit les squares à gauche/droite/en haut/en bas
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			//Limite à gauche
			if (j > 0)
			{
				tabSquare[i][j]->upperSquare = tabSquare[i][j - 1];
			}
			//Limite à droite
			if (j <20)
			{
				tabSquare[i][j]->lowerSquare = tabSquare[i][j+ 1];
			}
			//Limite en haut
			if (i > 0)
			{
				tabSquare[i][j]->leftSquare = tabSquare[i-1][j];
			}
			//Limite en bas
			if (i <20)
			{
				tabSquare[i][j]->rightSquare = tabSquare[i + 1][j];
			}
			//Définit le startSquare
            if (tabSquare[i][j]->value == 'D')
                startSquare = tabSquare[i][j];
		}
	}

	streamInput.clear();
	streamInput.close();
}

/// <summary>
/// Finalizes an instance of the <see cref="Labyrinth"/> class.
/// </summary>
Labyrinth::~Labyrinth()
{
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			delete tabSquare[i][j];
		}
	}
}

/// <summary>
/// La map en string.
/// </summary>
/// <returns>Une string représentant la map</returns>
std::string Labyrinth::ToString()const
{
	string mapToStr = "";
	for (size_t j = 0; j < 20; j++)
	{
		for (size_t i = 0; i < 20; i++)
		{
			mapToStr += tabSquare[i][j]->value;
		}
		mapToStr += "\n";
	}
	return mapToStr;
}

/// <summary>
/// Accès au startSquare.
/// </summary>
/// <returns>Le premier square</returns>
Square* Labyrinth::GetStartSquare()const
{
	return startSquare;
}
