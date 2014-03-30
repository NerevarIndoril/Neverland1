#include "main.h"
#include "Game.cpp"


int main()
{
	Game game;
	game.Init();
	
	game.cellManager.GenCells();

	game.cellManager.tileMap.LoadTileMap(game.resManager,Textures::Tileset,Vector2u(64,64),100,100);

	game.unitManager.LoadUnit(game.resManager,Textures::Hero,"Nerevar",64,64,100,game.resManager.MainFont);
	game.unitManager.LoadUnit(game.resManager,Textures::Skeleton,"Skeleton",128,128,100,game.resManager.MainFont);
	

for (unsigned int i=0;i<game.unitManager.count;i++)
{
	if (game.cellManager.tileMap.IsPathableCell(game.unitManager.units[i].sprite.getPosition().x/64,game.unitManager.units[i].sprite.getPosition().y/64)==0)
	{
	Vector2f v=game.cellManager.tileMap.FindPathableCell(game.unitManager.units[i].sprite.getPosition().x/64,game.unitManager.units[i].sprite.getPosition().y/64);
	game.unitManager.units[i].sprite.setPosition(v.x*64,v.y*64);
	}
}

	while (game.window.isOpen())
    {

		game.Update();

		game.Draw();

    }
	

    return 0;
}