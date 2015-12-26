#include "Animation.hh"

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.hh"
#include "../assets.hh"


Animation::Animation(Image * pImage,int pFrames,float pSpeed):
image(pImage),
frames(pFrames),
speed(pSpeed)
{
  clip.x = 0;
  clip.y = 0;
  clip.w = image->getWidth() / frames;
  clip.h = image->getHeight();
}


void Animation::update(float deltaTime)
{
  elapsed += deltaTime;

  if (elapsed > speed * frames)
  {
    elapsed -= speed * frames;
  }
}


void Animation::render(SDL_Renderer * renderer,int x,int y)
{
  //get the current frame of the animation
  int currentFrame = (int)(elapsed / speed);

  //get the frame's rect
  clip.x = (image->getWidth() / frames) * currentFrame;

  //display it
  image->render(renderer,x,y,&clip);
}


Animation * Animation::duplicate()
{
  return new Animation(image,frames,speed);
}
