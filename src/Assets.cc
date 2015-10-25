#include "Assets.hh"


void Assets_init()
{
  images.init(renderer);
  animations.init(assets->images);
  font.init(FONT_FILE,assets->images);
}
