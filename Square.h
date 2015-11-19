#ifndef SQUARE_H
#define SQUARE_H

struct Square final
{
	Square(int px, int py, char pvalue, bool pvisited); 
	~Square() = default;
	int x; // Position en x
	int y; // Position en y
	char value; // Valeur de l'emplacement (mur, libre, début, sortie)
	bool visited; // Si on est déjà passé ici.
	Square* upperSquare; // Le Square au-dessus
	Square* rightSquare; // Le Square à droite
	Square* leftSquare;  // Le Square à gauche
	Square* lowerSquare; // Le Square au-dessous
};

#endif // SQUARE_H
