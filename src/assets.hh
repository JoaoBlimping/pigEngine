//provides a global access point to all of the game's assets that need to be globally
//accessable


#ifndef ASSETS_H
#define ASSETS_H

#include "things/Manager.hh"
#include "things/Image.hh"
#include "things/Animation.hh"
#include "things/Sound.hh"
#include "things/Font.hh"


/**
 * functor for the loading of an image from a given file
 */
struct ImageLoader
{
  Image * operator()(char const * filename,SDL_Renderer * renderer);
};

/**
 * functor for the loading of an animation from a given file
 */
struct AnimationLoader
{
  Animation * operator()(char const * filename,SDL_Renderer * renderer);
};

/**
 * functor for the loading of a sound from a given file
 */
struct SoundLoader
{
  Sound * operator()(char const * filename,SDL_Renderer * renderer);
};

/**
 * functor for the loading of a font from a given file
 */
struct FontLoader
{
	Font * operator()(char const * filename,SDL_Renderer * renderer);
};


/**
 * Manager for Images
 */
extern Manager<Image,ImageLoader> assets_images;

/**
 * Manager for Animations
 */
extern Manager<Animation,AnimationLoader> assets_animations;

/**
 * Manager for Sounds
 */
extern Manager<Sound,SoundLoader> assets_sounds;

/**
 * The game's font
 */
extern Manager<Font,FontLoader> assets_fonts;

/**
 * Initialises assets, and must be called before the managers can be used.
 */
void assets_init(SDL_Renderer * renderer);


#endif
