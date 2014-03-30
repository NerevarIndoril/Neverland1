#include "main.h"
#include "Cell.h"

class CellManager
{

public:
	TileMap tileMap;

void GenCells()
{
	int x=0,y=0;
	for (unsigned int i=0;i<10000;i++)
	{
			if (x<19)
			{
				x=x+1;
			}
			else
			{
				x=0;
			}
			
			if (i%19==0)
			{
				y=y+1;
			}
			
			int random=GetRandomInt(0,2);
			if (random==0)
			{
				tileMap.cells.push_back(Cell(1,x,y,0));
			}
			else if (random==1)
			{
				tileMap.cells.push_back(Cell(1,x,y,1));
			}
			else if (random==2)
			{
				tileMap.cells.push_back(Cell(0,x,y,2));
			}
	}
}
};



