//manages the game's asset

#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H


#include <SDL.h>

#include "Image.h"
#include "Animation.h"


namespace AssetManager
{
  extern char const * ANIMATION_DIR;
  extern char const * ANIMATION_LIST;
  extern char const * IMAGE_DIR;
  extern char const * IMAGE_LIST;

  //the images
  extern Image * images;

  //the animations
  extern Animation * animations;

  //this is when all of the loading happens
  void init(SDL_Renderer * renderer);
}


#endif
