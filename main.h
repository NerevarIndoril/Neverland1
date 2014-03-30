#ifndef MAIN_H
#define MAIN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <memory>

using namespace std;
using namespace sf;

#define GetRandomInt(min,max) rand() % ((max + 1) - min) + min;

namespace Textures
{
	enum ID { Hero , Skeleton ,  Cursor ,Tileset };
}

class Input
{
public:
	unsigned int Up,Down,Left,Right;
	unsigned int MouseLeft,MouseRight;
	unsigned int MouseX,MouseY;
	unsigned int Esc,Enter;

Input()
{
	Up,Down,Left,Right=0;
	MouseLeft,MouseRight=0;
	Esc,Enter=0;
	MouseX=Mouse::getPosition().x;
	MouseY=Mouse::getPosition().y;
}
Vector2f UpdateView()
{
	Vector2f update=Vector2f(0,0);
	if (Up!=0)
	{
		update=Vector2f(0,-64);

	}
	if (Down==1)
	{
		update=Vector2f(0,64);
	}
	if (Left==1)
	{
		update=Vector2f(-64,0);
	}
	if (Right==1)
	{
		update=Vector2f(64,0);
	}
	return update;
}
void CheckInput()
{
	Up=Keyboard::isKeyPressed(Keyboard::W);
	Down=Keyboard::isKeyPressed(Keyboard::S);
	Left=Keyboard::isKeyPressed(Keyboard::A);
	Right=Keyboard::isKeyPressed(Keyboard::D);
	Esc=Keyboard::isKeyPressed(Keyboard::Escape);
	Enter=Keyboard::isKeyPressed(Keyboard::Comma);
	MouseX=Mouse::getPosition().x;
	MouseY=Mouse::getPosition().y;
}

void ClearInput()
{
	Up=0;
	Down=0;
	Left=0;
	Right=0;
	Esc=0;
	Enter=0;
}
};



#endif