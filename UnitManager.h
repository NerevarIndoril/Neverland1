#include "main.h"
#include "Unit.h"
#include "ResManager.h"

class UnitManager
{
public:
	vector<Unit> units;
	unsigned int count;

UnitManager()
{
	count=0;
}

void DrawUnitText(RenderTarget& target)
{
	for (unsigned int i=0;i<count;i++)
	{
		int dx=units[i].text.getLocalBounds().width/2;

	units[i].text.setPosition(units[i].sprite.getPosition().x+32-dx,units[i].sprite.getPosition().y-20);
	target.draw(units[i].text);
	}
}

void Draw(RenderTarget& target) const
    {
		for (unsigned int i=0;i<count;i++)
		{
			units[i].draw(target);
		}
	}
  
void LoadUnit(ResManager &resManager,Textures::ID id,const string &_name,Uint32 _x,Uint32 _y,Uint32 _hp,Font &font)
{
	Unit unit;
	unit.sprite.setTexture(resManager.Get(id));
	unit.sprite.setPosition(_x,_y);
	unit.name=_name;
	unit.x=_x;
	unit.y=_y;
	unit.hp=_hp;
	unit.text.setFont(font);
	unit.text.setString(unit.name);	
	unit.text.setCharacterSize(16); 
	unit.text.setColor(Color::White);

	units.push_back(unit);
	count=count+1;
}

};

