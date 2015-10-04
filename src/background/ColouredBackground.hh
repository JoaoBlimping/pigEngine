//a background that is a nice colour


#ifndef COLOURED_BACKGROUND_H
#define COLOURED_BACKGROUND_H


#include "Background.hh"

#include "../Assets.hh"


class ColouredBackground:public Background
{
public:
  //sets the colour that it fills the background with
  ColouredBackground(char pRed,char pGreen,char pBlue,char pAlpha);

  //might be useful for animated backgrounds
  virtual void update(float deltaTime);

  //display the background with dynamic width and height
  virtual void render(SDL_Renderer * renderer,int screenWidth,int screenHeight);

private:
  //the components of the colour it displays
  char red;
  char green;
  char blue;
};


class ColouredBackgroundFactory:public BackgroundFactory
{
  //creates a TileBackground
  virtual Background * createBackground(Assets const * const assets);
};


#endif
