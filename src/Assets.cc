#include "Assets.hh"


void Assets_init()
{
  images.init(renderer);
  animations.init(images);
  fonts.init(images);
  //TODO: SoundManager will probably need to be initialised too one day
}
