#ifndef SKIN_H
#define SKIN_H


#include <SDL2/SDL.h>

#include "Image.hh"


/** used to draw rectangles that have a sexy skin applied to them
 * the skin breaks the given image up into 9 parts, diving it in three both horizontally
 * and vertically, so it's like sides, corners and the middle, which is tiled. you get the
 * idea */
class Skin
{
public:
	/** creates the skin with it's image it uses
	 * the skin does not take ownership of the image, so deallocation must be done
	 * elsewhere */
	Skin(Image * image);

	/** does the rendering as this class was born to do */
	void render(SDL_Renderer * renderer,int x,int y,int width,int height);

private:
	/** the image containing the skin */
	Image * image;
};


#endif
