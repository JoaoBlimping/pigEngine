//this is an interface for things that can fill in the background


#ifndef BACKGROUND_H
#define BACKGROUND_H


class Background
{
public:
  //might be useful for animated backgrounds
  virtual void update(float deltaTime) = 0;

  //display the background
  virtual void render(SDL_Renderer * renderer,int screenWidth,
                      int screenHeight) = 0;
};


class BackgroundFactory


#endif
