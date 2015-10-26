#include "Assets.hh"


void Assets_init(SDL_Renderer * renderer)
{
  Assets_images.init(renderer);
  Assets_animations.init(&Assets_images);
  Assets_fonts.init(&Assets_images);
  //TODO: SoundManager will probably need to be initialised too one day
}
