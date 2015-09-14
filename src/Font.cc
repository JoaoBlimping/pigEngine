#include "Font.h"


Font::Font(Image * pImage,int pCharWidth):
image(pImage),
charWidth(pCharWidth)
{
  clip.x = 0;
  clip.y = 0;
  clip.w = charWidth;
  clip.h = image->getHeight();
}


Font::Font(char const * filename,ImageManager * images)
{
  //open the file and shit
  ifstream fontFile(filename);
  if (!fontFile.is_open())
  {
    printf("can't open font file %s\n");
    return;
  }

  //read the stuff from the file
  int imageID;
  fontFile >> imageID;
  fontFile >> charWidth;

  //close the file
  fontFile.close();
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
    currentX += charWidth;

    if (currentX > x + width - charWidth)
    {
      currentX = x;
      y += image->getHeight();
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
