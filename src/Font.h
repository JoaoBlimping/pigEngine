//a nice bitmap font which will look ever so nice


#ifndef FONT_H
#define FONT_H


#include <SDL.h>

#include "Image.h"


int const LETTERS_START = 97;
int const LETTERS_END = 122;
int const SYMBOLS_START = 33;
int const SYMBOLS_END = 46;


class Font
{
public:
  //creates the font with it's image data and the width of a character
  Font(Image * pImage,int pCharWidth);

  //creates a font from a file that contains the image number character width
  Font(char const * filename);

  //render some text to the screen
  void renderString(SDL_Renderer * renderer,char const * text,int x,int y,
              int width = 0);

  //render a single character to the screen
  void renderCharacter(SDL_Renderer * renderer,char character,int x,int y);

private:
  //the image that contains the characters
  Image * image;

  //the width of each character
  int charWidth;

  //defines the clipping and that
  SDL_Rect clip;
};


#endif
