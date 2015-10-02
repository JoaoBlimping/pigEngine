//a background made up of a tiled image


#ifndef TILE_BACKGROUND_H
#define TILE_BACKGROUND_H


#include "Background.hh"

#include "Image.hh"


class TileBackground:public Background
{
public:
  //puts the image into it
  TileBackground(Image * pTile);

  //might be useful for animated backgrounds
  virtual void update(float deltaTime);

  //display the background with dynamic width and height
  virtual void render(SDL_Renderer * renderer,int screenWidth,int screenHeight);

private:
  //the image that gets repeated in the background
  Image * tile;
};


class TileBackgroundFactory:public BackgroundFactory
{
  //creates a TileBackground
  virtual Background * createBackground();
};


#endif
