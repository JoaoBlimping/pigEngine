//provides a global access point to all of the game's assets that need to be globally
//accessable


#ifndef ASSETS_H
#define ASSETS_H

#include "Manager.hh"
#include "things/Animation.hh"
#include "managers/ImageManager.hh"
#include "managers/AnimationManager.hh"
#include "managers/SoundManager.hh"
#include "managers/FontManager.hh"


//the managers of the different kinds of assets
extern ImageManager assets_images;
extern Manager<Animation> assets_animations;
extern FontManager assets_fonts;
extern SoundManager assets_sounds;

//initialises it and loads all the stuff that needs to be loaded and that
void assets_init(SDL_Renderer * renderer);


#endif
