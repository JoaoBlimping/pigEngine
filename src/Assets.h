//contains a bunch of assets and shit


#ifndef ASSETS_H
#define ASSETS_H


#include "ImageManager.h"
#include "AnimationManager.h"
#include "SoundManager.h"


struct Assets
{
  ImageManager * images;
  AnimationManager * animations;
  SoundManager * sounds;
};


#endif
