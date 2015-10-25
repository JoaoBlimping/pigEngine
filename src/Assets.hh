//provides a global access point to all of the game's assets that need to be globally
//accessable


/**
 * TODO: add a background abstract factory to Assets
 * this way you can create them as they are needed.
 * all of the things that just factories will need
 * to use filenames that are just numbers and .pig.
 *
 * this won't mean entities will need to be named after numbers in their files
 * I will also create a repository class that stores things after creating them
 */


#ifndef ASSETS_H
#define ASSETS_H


#include "ImageManager.hh"
#include "AnimationManager.hh"
#include "SoundManager.hh"
#include "things/Font.hh"


//the managers of the different kinds of assets
ImageManager images;
AnimationManager animations;
Font font;
SoundManager sounds;

//initialises it and loads all the stuff that needs to be loaded and that
void Assets_init();


#endif
