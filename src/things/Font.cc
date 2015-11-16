#include "Font.hh"

#include <iostream>
#include <fstream>
#include <stdio.h>

#include "../assets.hh"


using namespace std;


Font::Font(Image * pImage,int pCharWidth,int pSpacing):
image(pImage),
charWidth(pCharWidth),
spacing(pSpacing)
{
  clip.x = 0;
  clip.y = 0;
  clip.w = charWidth;
  clip.h = image->getHeight();
}


void Font::renderString(SDL_Renderer * renderer,char const * text,int x,int y,
                  int width)
{
  int currentX = x;

  while (*text != '\0')
  {
    //display the letter in the right place
    renderCharacter(renderer,*text,currentX,y);

    //increment the things
    currentX += charWidth + spacing;

    if ((currentX > x + width - (charWidth + spacing)) && (*text == ' '))
    {
      currentX = x;
      y += image->getHeight() + spacing;
    }

    //go to the next letter
    text++;
  }
}


void Font::renderCharacter(SDL_Renderer * renderer,char character,int x,int y)
{
  //if it's a letter
  if (character >= LETTERS_START && character <= LETTERS_END)
  {
    clip.x = (character - LETTERS_START) * charWidth;
  }
  //if it's a symbol
  else if (character >= SYMBOLS_START && character <= SYMBOLS_END)
  {
    clip.x = (character - SYMBOLS_START) * charWidth;
  }
  //otherwise don't draw it
  else
  {
    return;
  }

  //now draw the character in the place
  image->render(renderer,x,y,&clip);
}
