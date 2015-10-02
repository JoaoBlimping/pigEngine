//a background made up of a tiled image


#ifndef TILE_BACKGROUND_H
#define TILE_BACKGROUND_H


#include "Image.h"


class TileBackground
{
public:
  //puts the image and the size of the window into it

  //might be useful for animated backgrounds
  virtual void update(float deltaTime);

  //display the background with dynamic width and height
  virtual void render(SDL_Renderer * renderer,int screenWidth,int screenHeight);

private:
  //the image that gets repeated in the background
  Image * tile;
};


#endif
