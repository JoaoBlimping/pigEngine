#ifndef TILE_MAP_H
#define TILE_MAP_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "things/Image.hh"


#define TILE_WIDTH 32
#define TILE_HEIGHT 32


/** A map of tile ids that can display itself using some tileset and also gives collision
 * information about the tiles */
class TileMap
{
public:
	/** creates a tilemap */
	TileMap(int width,int height,int nBackLayers,int nFrontLayers,Tile * tiles,
			bool * collisions,Image * tileset);

	/** deallocates the map's tile data but not the tileset */
	~TileMap();

	/** displays the tilemap's back part
	 * uses the camera position to display the tiles to the screen */
	void renderBack(SDL_Renderer * renderer);

	/** displays the tilemap's front part
	 * uses the camera position to display the tiles to the screen
	 */
	void renderFront(SDL_Renderer * renderer);

	/** displays a single tile at a given location */
	void renderTile(SDL_Renderer * renderer,int x,int y,int tile);

	/** centres the camera on a specified position
	 * sets the target centre position of the camera */
	void centre(int x,int y);

private:
	/** rectangle used to draw do the clipping and that */
	static SDL_Rect clip(0,0,TILE_WIDTH,TILE_HEIGHT);

	/** the horizontal position of the camera */
	int cameraX;

	/** the vertical position of the camera */
	int cameraY;

	/** the width of the map */
	int width;

	/** the height of the map */
	int height;

	/** the number of layers that go behind characters and stuff */
	int nBackLayers;

	/** the number of layers that go in front of characters and stuff */
	int nFrontLayers;

	/** The tiles that make up the level
	 * taken responsibility for */
	Tile * * * tiles;

	/** the collision information
	 * taken responsibility for */
	bool * * collisions;

	/** the image that the tiles are rendered from
	 * taken responsibility for */
	Image * tileset;
};


#endif
