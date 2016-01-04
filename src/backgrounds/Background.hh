//this is an interface for things that can fill in the background


#ifndef BACKGROUND_H
#define BACKGROUND_H


#include <SDL2/SDL.h>


class Background
{
public:
  //a virtual destructor so that sub classes can destruct if they wish
  virtual ~Background(){};

  //might be useful for animated backgrounds
  virtual void update(float deltaTime) = 0;

  //display the background
  virtual void render(SDL_Renderer * renderer,int screenWidth,int screenHeight) = 0;
};


#endif
