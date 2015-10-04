#include "Font.hh"

#include <iostream>
#include <fstream>
#include <stdio.h>

#include "../ImageManager.hh"


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


Font::Font(char const * filename,ImageManager const * const images)
{
  //open the file and shit
  ifstream fontFile(filename);
  if (!fontFile.is_open())
  {
    printf("can't open font file %s\n",filename);
    return;
  }

  //read the stuff from the file
  int imageID;
  fontFile >> imageID;
  fontFile >> charWidth;
  fontFile >> spacing;

  image = images->getImage(imageID);

  //close the file
  fontFile.close();

  //do those other things
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
