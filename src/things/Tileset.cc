#include "Tileset.hh"

#include <stdint.h>


Tileset::Tileset(Image * pImageData,uint8_t * pCollisionData):
imageData(pImageData),
collisionData(pCollisionData)
{}


Tileset::~Tileset()
{
	delete[] collisionData;
}


void Tileset::renderTile(Tile tile,int x,int y,SDL_Renderer * renderer)
{
	
}


bool Tileset::canWalk(Tile a,Tile b,direction dir)
{
	return (b >> dir) & 1;
}
