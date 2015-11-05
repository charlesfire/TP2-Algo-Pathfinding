

struct Square final
{
	Square(int px,int py,char pvalue,bool pvisited);
	~Square();
	int x;
	int y;
	char value;
	bool visited;
	Square* upperSquare;
	Square* rightSquare;
	Square* leftSquare;
	Square* lowerSquare;
};