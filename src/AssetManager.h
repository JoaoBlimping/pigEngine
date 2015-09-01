//manages graphics


#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H


#include "Image.h"
#include "Animation.h"


char const * ANIMATION_DIR = "assets/animations";
char const * IMAGE_DIR = "assets/images";
char const * LIST = "list";


namespace AssetManager
{
  //the images
  Image * images;

  //the animations
  Animation * animations;

  //this is when all of the loading happens
  void init();
}


#endif
