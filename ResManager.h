#include "main.h"

#ifndef RESMANAGER_H
#define RESMANAGER_H
class ResManager
{
public:

	map<Textures::ID,unique_ptr<Texture>>TextureMap;
	vector <Texture> Textures;
	Font MainFont;

bool LoadFont(const string &Name)
{
	return MainFont.loadFromFile(Name);
}

void Load(Textures::ID id, const string& filename)
{
	unique_ptr<Texture> texture(new Texture());
	texture->loadFromFile(filename);
	TextureMap.insert(make_pair(id, move(texture)));
}

Texture& Get(Textures::ID id)
{
auto found = TextureMap.find(id);
return *found->second;
}


};

#endif