//manages animations for you!!!!


#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H


#include <vector>

#include "ImageManager.hh"
#include "../things/Animation.hh"


class AnimationManager
{
public:
  //some useful constants for ye
  static char const * ANIMATION_DIR;
  static char const * ANIMATION_LIST;

  //loads all the animations and that
  void init(ImageManager const * const imageManager);

  //gives you an item from the maneger
  Animation * getAnimation(int index)const;

private:
  std::vector<Animation *> animations;

};


#endif
