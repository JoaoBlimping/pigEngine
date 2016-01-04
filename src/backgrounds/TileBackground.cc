#include "TileBackground.hh"

#include <math.h>
#include <iostream>

#include <SDL2/SDL.h>

#include "../assets.hh"


TileBackground::TileBackground(Image * tile):
tile(tile)
{}

void TileBackground::update(float deltaTime)
{
  //does nothing
}

void TileBackground::render(SDL_Renderer * renderer,int screenWidth,
                            int screenHeight)
{
  int xTiles = ceil(screenWidth / tile->getWidth());
  int yTiles = ceil(screenHeight / tile->getHeight());

  for (int x = 0;x < xTiles;x++)
  {
    for (int y = 0;y < yTiles;y++)
    {
      tile->render(renderer,x * tile->getWidth(),y * tile->getHeight());
    }
  }
}


Background * TileBackgroundFactory::operator()(std::istream * data)
{
	int imageIndex;
	data->operator>>(imageIndex);
	return new TileBackground(assets_images.getItem(imageIndex));
}
