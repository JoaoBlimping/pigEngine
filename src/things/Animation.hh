//a spritesheet animation


#ifndef ANIMATION_H
#define ANIMATION_H


#include <stdio.h>
#include <iostream>
#include <fstream>

#include <SDL.h>

#include "Image.hh"


class Animation
{
public:
  //creates the animation!!!!!!!!
  Animation(Image * pImage,int pFrames,float pSpeed);

  //updates the animation with the passed time
  void update(float deltaTime);

  //displays the animation with the given renderer
  void render(SDL_Renderer * renderer,int x,int y);

  //gives you a copy of this animation object
  Animation * duplicate();

private:
  //the image the animation is based on
  Image * image;

  //the number of frames
  int frames;

  //the time each frame lasts for
  float speed;

  //the current time that the animation is at
  float elapsed;

  //defines the clipping and that
  SDL_Rect clip;
};


/**
 * functor for loading animations from file
 */
struct AnimationLoader
{
  Animation * operator()(char const * filename,SDL_Renderer * renderer);
}


#endif
