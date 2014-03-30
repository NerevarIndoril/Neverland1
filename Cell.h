#include "main.h"
#include "ResManager.h"

class Cell
{
public:
	unsigned int pathable;
	unsigned int x,y;
	unsigned int textureId;
	Cell(){}

Cell(unsigned int _pathable,unsigned int _x,unsigned int _y,unsigned int _textureId)
{
	pathable=_pathable;
	x=_x;
	y=_y;
	textureId=_textureId;
}

};

class TileMap : public Drawable, public Transformable
{
public:
	VertexArray vertices;
    Texture texture;
	Vector2u tileSize; 
	unsigned int width;
	unsigned int height;
	vector<Cell> cells;

unsigned int IsPathableCell(int x,int y)
{
	return cells[y*width+x].pathable;
}

Vector2f FindPathableCell(int x,int y)
{
	int tx=x;
	int ty=y;
	while(IsPathableCell(tx,ty)==0)
{
	int random=GetRandomInt(0,4);

	if (random==0&&tx+1<100&&ty+1<100)
	{
		tx=tx+1;
		ty=ty+1;
	}
	else if (random==1&&tx-1>=0&&ty-1>=0)
	{
		tx=tx-1;
		ty=ty-1;
	}
	else if (random==2&&tx+1<100&&ty-1>=0)
	{
		tx=tx+1;
		ty=ty-1;
	}
	else if (random==3&&tx-1>=0&&ty+1<100)
	{
		tx=tx-1;
		ty=ty+1;
	}
	else if (random==4&&tx-1>=0&&ty-1>=0)
	{
		tx=tx-1;
		ty=ty-1;
	}
}
	return Vector2f(tx,ty);
}



bool UpdateCell(int x,int y,unsigned int newPathable,unsigned int newTextureId)
	{
		cells[y*width+x].pathable=newPathable;
		cells[y*width+x].textureId=newTextureId;

		int tu = cells[y*width+x].textureId % (texture.getSize().x / tileSize.x);
        int tv = cells[y*width+x].textureId / (texture.getSize().x / tileSize.x);

		Vertex* quad = &vertices[(x + y * width) * 4];

		// define its 4 texture coordinates
        quad[0].texCoords = Vector2f(tu * tileSize.x, tv * tileSize.y);
        quad[1].texCoords = Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
        quad[2].texCoords = Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
        quad[3].texCoords = Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		return true;
	}

bool LoadTileMap(ResManager &resManager,Textures::ID id, Vector2u _tileSize,  unsigned int _width, unsigned int _height)
{
		tileSize=_tileSize;
		width=_width;
		height=_height;

		texture=resManager.Get(id);

        vertices.setPrimitiveType(Quads);
        vertices.resize(width * height * 4);

        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
				int tileNumber = cells[i + j * width].textureId;

                int tu = tileNumber % (texture.getSize().x / tileSize.x);
                int tv = tileNumber / (texture.getSize().x / tileSize.x);

                Vertex* quad = &vertices[(i + j * width) * 4];

                quad[0].position = Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                quad[0].texCoords = Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
}

virtual void draw(RenderTarget& target, RenderStates states) const
    {
        
        states.transform *= getTransform();

        states.texture = &texture;

        target.draw(vertices, states);
    }
    
};