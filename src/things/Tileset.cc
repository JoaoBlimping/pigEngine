#include "Tileset.hh"

#include <stdint.h>


Tileset::Tileset(Image * pImageData,uint8_t * collisionData)
{

}


Tileset::~Tileset()
{

}


void Tileset::renderTile(Tile tile,int x,int y,SDL_Renderer * renderer)
{
	
}


bool Tileset::canWalk(Tile a,Tile b,direction dir)
{
	//if tile b is completely impassable
	if (!(b & 1))
	{
		return false;
	}
	
	//test if it is blocked for the given direction
	return (b >> dir) & 1;
}
