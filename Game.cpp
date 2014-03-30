#include "ResManager.h"
#include "UnitManager.h"
#include "CellManager.h"

class Game
{
public:
	int State;

	ResManager resManager;
	UnitManager unitManager;
	CellManager cellManager;

	Clock clock;
	int elapsed;

	VideoMode videomode;
	RenderWindow window;
	View defaultView;
	View currView;

	Input input;

	Sprite cursor;
	Vector2f cursorPos;

void Init()
{
	State=1;
	srand(time(0));
	videomode=videomode.getDesktopMode();
	defaultView.reset(FloatRect(0, 0, videomode.width, videomode.height));
	currView.reset(FloatRect(0, 0, videomode.width, videomode.height));
	window.create(videomode, "Neverland",Style::Default);
	window.setView(currView);
	window.setMouseCursorVisible(false);

	resManager.LoadFont("arial.ttf");

	resManager.Load(Textures::Skeleton,"skeleton5.png");
	resManager.Load(Textures::Cursor,"cursor.png");
	resManager.Load(Textures::Tileset,"tileset.png");
	resManager.Load(Textures::Hero,"hero.png");
	
	cursor.setTexture(resManager.Get(Textures::Cursor));
}

void Update()
{
	 Event event;

	 if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.setMouseCursorVisible(true);
				window.close();
			}
     while (window.pollEvent(event))
        {
			switch(event.type)
			{

			// отлавливаем,нажато ли что-нибудь
			case Event::KeyPressed:
			case Event::KeyReleased:
			case Event::MouseButtonPressed:
			case Event::MouseButtonReleased:
			case Event::MouseMoved:
			input.CheckInput();
			break;

			//отлавливаем,произошло ли события закрытия
			case Event::Closed:
			window.setMouseCursorVisible(true);
            window.close();
			}
			
        }

		cursorPos=window.mapPixelToCoords(Vector2i(input.MouseX,input.MouseY));
		cursor.setPosition(Vector2f(int(cursorPos.x/64)*64,int(cursorPos.y/64)*64));

		elapsed = elapsed+clock.restart().asMilliseconds();

		currView.setCenter(currView.getCenter()+input.UpdateView());
		window.setView(currView);


		input.ClearInput();
		
        
}

void Draw()
{
	window.clear();

	window.draw(cellManager.tileMap);
	unitManager.Draw(window);
	unitManager.DrawUnitText(window);
	window.draw(cursor);
	window.display();
}


};