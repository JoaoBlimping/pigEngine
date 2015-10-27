#include "assets.hh"

#include "things/Animation.hh"


ImageManager assets_images;
Manager<Animation> assets_animations("assets/animations/","assets/animations/list.pig",
                                   &loadAnimationFromFile);
FontManager assets_fonts;
SoundManager assets_sounds;


void assets_init(SDL_Renderer * renderer)
{
  assets_images.init(renderer);
  assets_animations.init(renderer);
  assets_fonts.init(&assets_images);
  //TODO: SoundManager will probably need to be initialised too one day
}
