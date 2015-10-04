//contains a bunch of assets and shit


#ifndef ASSETS_H
#define ASSETS_H


#include "ImageManager.hh"
#include "AnimationManager.hh"
#include "SoundManager.hh"
#include "things/Font.hh"


struct Assets
{
  ImageManager * images;
  AnimationManager * animations;
  SoundManager * sounds;
  Font * font;
};


#endif
