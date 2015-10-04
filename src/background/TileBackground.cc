#include "TileBackground.hh"

#include <math.h>

#include "../Assets.hh"


TileBackground::TileBackground(Image * pTile):
tile(pTile)
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


Background * TileBackgroundFactory::createBackground(Assets const * const assets)
{

}
