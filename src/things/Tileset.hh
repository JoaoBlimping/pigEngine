#ifndef TILESET_H
#define TILESET_H


#include <stdint.h>

#include "Tile.hh"
#include "Image.hh"


/**
 * draws tiles and administers collision info
 */
class Tileset
{
public:
	/**
	 * create the tileset
	 * create the tileset and set it's image and it's collision data
	 */
	Tileset(Image * pImageData,uint8_t * pCollisionData);

	/**
	 * deletes the collision data
	 * deallocates the tileset's memory and also the collision data, but not the image data
	 */
	~Tileset();

	/**
	 * display a tile on the screen at a given position
	 */
	void renderTile(Tile tile,int x,int y,SDL_Renderer * renderer);
	
	/**
	 * tells the asker whether you can walk from one tile to another in a given direction
	 */
	bool canWalk(Tile a,Tile b,direction dir);


private:
	int tileSize;

	/**
	 * the Image that contains the visual tiles
	 * This is the source image that the tileset uses to render. The tileset does not take
	 * responsibility for deleting this.
	 */
	Image * imageData;

	/**
	 * contains collision data for each tile in the tileset
	 * different data is stored in each bit of the byte, first it checks if the tile is
	 * completely unpassable, then pass for each direction.
	 */
	uint8_t * collisionData;
};


#endif
