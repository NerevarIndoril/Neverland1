#include "main.h"

class Unit: public Drawable, public Transformable
{
public:
	Sprite sprite;
	Texture texture;
	Text text;
	string name;
	Uint32 x;
	Uint32 y;
	Uint32 hp;

Unit(){}

void SetPosition(Uint32 newX,Uint32 newY)
{
	x=newX;
	y=newY;
}

Vector2i GetPosition()
{
	return Vector2i(x,y);
}

void DamageTarget(Unit &caster,Unit &target,float damage)
{
	target.hp=target.hp-damage;
}

virtual void draw(RenderTarget& target) const
    {
        target.draw(sprite);
    }

virtual void draw(RenderTarget& target, RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &texture;

        // draw the vertex array
        target.draw(sprite, states);
    }

};