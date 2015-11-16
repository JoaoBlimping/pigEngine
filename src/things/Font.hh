//a nice bitmap font which will look ever so nice


#ifndef FONT_H
#define FONT_H


#include <stdio.h>
#include <iostream>
#include <fstream>

#include <SDL.h>

#include "Image.hh"


int const LETTERS_START = 97;
int const LETTERS_END = 122;
int const SYMBOLS_START = 33;
int const SYMBOLS_END = 46;


class Font
{
public:
  //creates the font with it's image data and the width of a character and space
  Font(Image * pImage,int pCharWidth,int pSpacing);

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

  //the space between each character and line
  int spacing;

  //defines the clipping and that
  SDL_Rect clip;
};


#endif
