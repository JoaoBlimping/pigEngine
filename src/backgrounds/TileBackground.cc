#include "TileBackground.hh"

#include <math.h>
#include <stdio.h>

#include <SDL2/SDL.h>

#include "../assets.hh"


TileBackground::TileBackground(Image * tile,float xDrift,float yDrift):
tile(tile),
xDrift(xDrift),
yDrift(yDrift),
xOffset(0),
yOffset(0)
{}

void TileBackground::render(SDL_Renderer * renderer,int screenWidth,int screenHeight,float deltaTime)
{
	xOffset += xDrift * deltaTime;
	yOffset += yDrift * deltaTime;
	while (xOffset > tile->getWidth()) xOffset -= tile->getWidth();
	while (yOffset > tile->getHeight()) yOffset -= tile->getHeight();
	while (xOffset < 0) xOffset += tile->getWidth();
	while (yOffset < 0) yOffset += tile->getHeight();


	int xTiles = ceil(screenWidth / tile->getWidth()) + 1;
	int yTiles = ceil(screenHeight / tile->getHeight()) + 1;

	for (int x = -1;x < xTiles;x++)
	{
		for (int y = -1;y < yTiles;y++)
		{
			tile->render(renderer,x * tile->getWidth() + xOffset,y * tile->getHeight() + yOffset);
		}
	}
}


Background * TileBackgroundFactory::operator()(StreamReader * data)
{
	int imageIndex = data->readInt();
	float xDrift = data->readFloat();
	float yDrift = data->readFloat();
	return new TileBackground(assets_images.getItem(imageIndex),xDrift,yDrift);
}
