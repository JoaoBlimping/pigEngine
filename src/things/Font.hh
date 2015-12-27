#ifndef FONT_H
#define FONT_H


#include <SDL2/SDL.h>

#include "Image.hh"


/** used to display a bitmap font
 * you give it an Image containing the font and the character width and spacing, and then
 * it can do everything you need */
class Font
{
public:
	/** creates the font with it's image data and the width of a character and space */
	Font(Image * image,int charWidth,int spacing);

	/** render some text to the screen */
	void renderString(SDL_Renderer * renderer,char const * text,int x,int y,int width = 0);

	/** render a single character to the screen */
	void renderCharacter(SDL_Renderer * renderer,char character,int x,int y);

	/** gives you the height of the string when it is rendered by this font */
	int getStringHeight(char const * text,int width);

private:
	/** Image containing the characters */
	Image * image;

	/** character width */
	int const charWidth;

	/** the space between each character and line */
	int const spacing;

	/** used for the clipping of the selected character */
	SDL_Rect clip;
};


#endif
