#include "TileMap.hh"

#include <math.h>


TileMap::TileMap(int width,int height,int nBackLayers,int nFrontLayers,Tile * tiles,
				 bool * collisions):
width(width),
height(height),
nBackLayers(nBackLayers),
nFrontLayers(nFrontLayers),
tiles(tiles),
collisions(collisions)
{}


TileMap::~TileMap()
{
	delete[] tiles;
	delete[] collisions;
}


void TileMap::renderBack(SDL_Renderer * renderer)
{
	int tileX = cameraX / TILE_WIDTH;
	int tileY = cameraY / TILE_HEIGHT;
	int tileScreenWidth = ceil(assets_getScreenWidth() / TILE_WIDTH);
	int tileScreenHeight = ceil(assets_getScreenHeight() / TILE_HEIGHT);

	for (int z = 0;z < nBackLayers;z++)
	{
		for (int x = 0;x < tileScreenWidth;x++)
		{
			for (int y = 0;y < tileScreenHeight;y++)
			{
				renderTile(renderer,(tileX + x) * TILE_WIDTH - cameraX,
						   (tileY + y) * TILE_HEIGHT - cameraY,tiles[x][y][z]);
			}
		}
	}

}


void TileMap::renderFront(SDL_Renderer * renderer)
{
	int tileX = cameraX / TILE_WIDTH;
	int tileY = cameraY / TILE_HEIGHT;
	int tileScreenWidth = ceil(assets_getScreenWidth() / TILE_WIDTH);
	int tileScreenHeight = ceil(assets_getScreenHeight() / TILE_HEIGHT);

	for (int z = nBackLayers;z < nBackLayers + nFrontLayers;z++)
	{
		for (int x = 0;x < tileScreenWidth;x++)
		{
			for (int y = 0;y < tileScreenHeight;y++)
			{
				renderTile(renderer,(tileX + x) * TILE_WIDTH - cameraX,
						   (tileY + y) * TILE_HEIGHT - cameraY,tiles[x][y][z]);
			}
		}
	}
}


void TileMap::renderTile(SDL_Renderer * renderer,int x,int y,int tile)
{
	//turn the 1D tile id into it's position in the tile sheet
	clip.x = tile * TILE_WIDTH;
	while (clip.x > tileset->getWidth())
	{
		clip.x -= tileset->getWidth();
		clip.y += TILE_HEIGHT;
	}
}


void TileMap::centre(int x,int y)
{
	cameraX = x - assets_getScreenWidth() / 2;
	cameraY = y - assets_getScreenHeight() / 2;
}
