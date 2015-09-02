//manages animations for you!!!!


#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H


#include <iostream>
#include <fstream>

#include "ImageManager.h"
#include "Animation.h"


class AnimationManager
{
public:
  //some useful constants for ye
  static char const * ANIMATION_DIR;
  static char const * ANIMATION_LIST;

  //creates a fresh new image manager just for you <3
  AnimationManager(ImageManager const * const imageManager);

  //gives you an item from the maneger
  Animation * getAnimation(int index)const;

private:
  std::vector<Animation *> animations;

};


#endif
