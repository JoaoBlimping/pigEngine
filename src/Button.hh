//a button you can check if you are clicking


#ifndef BUTTON_H
#define BUTTON_H


#include <SDL.h>

#include "Image.hh"


class Button
{
public:
  //the different frames of the button
  enum Frame
  {
    MOUSE_OUT,
    MOUSE_OVER,
    FRAMES_TOTAL
  };

  //creates a button with integers as the bounds
  Button(int pX,int pY,int const * pMouseX,int const * pMouseY,Image * pImage);

  //tests if the button contains a the mouse
  bool containsMouse();

  //renders the button to the screen
  void render(SDL_Renderer * renderer);

private:
  //the position of the button
  int x;
  int y;

  //the mouse position
  int const * mouseX;
  int const * mouseY;

  //the button's graphics
  Image * graphics;

  //the rect for the button's image clipping
  SDL_Rect clip;
};


#endif
