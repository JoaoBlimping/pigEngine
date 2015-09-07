//contains a bunch of assets and shit


#ifndef ASSETS_H
#define ASSETS_H


#include "ImageManager.h"
#include "AnimationManager.h"
#include "SoundManager.h"


struct Assets
{
  ImageManager * const imageManager;
  AnimationManager * const animationManager;
  SoundManager * const soundManager;
}


#endif
