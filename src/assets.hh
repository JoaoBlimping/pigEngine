//provides a global access point to all of the game's assets that need to be globally
//accessable


#ifndef ASSETS_H
#define ASSETS_H

#include "things/Manager.hh"
#include "things/Image.hh"
#include "things/Animation.hh"
#include "things/Sound.hh"
#include "things/Font.hh"


//the managers of the different kinds of assets
extern Manager<Image,ImageLoader> assets_images;
extern Manager<Animation,AnimationLoader> assets_animations;
extern Manager<Sound> assets_sounds;

//the font
extern Font * assets_font;

//initialises it and loads all the stuff that needs to be loaded and that
void assets_init(SDL_Renderer * renderer);


#endif
