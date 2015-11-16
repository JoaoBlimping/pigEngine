#include "Image.hh"

#include <stdio.h>
#include <iostream>
#include <fstream>


Image::~Image()
{
  free();
}


bool Image::loadFromFile(SDL_Renderer * renderer,char const * filename)
{
  //get rid of existing texture
  free();

  //the new texture
  SDL_Texture * newTexture = NULL;

  //load image at specified path
  SDL_Surface * loadedSurface = IMG_Load(filename);
  if (loadedSurface == NULL)
  {
    printf("unable to load image %s, SDL_image error: %s\n",filename,IMG_GetError());
    return false;
  }

  //create texture from surface pixels
  newTexture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
  if (newTexture == NULL)
  {
    printf("Unable to create texture from %s, SDL Error: %s\n",filename,SDL_GetError());
    SDL_FreeSurface(loadedSurface);
    return false;
  }

  //get the image's dimensions
  width = loadedSurface->w;
  height = loadedSurface->h;

  //remove the surface
  SDL_FreeSurface(loadedSurface);

  //make the new texture the current texture
  texture = newTexture;

  //it worked
  return true;
}


void Image::free()
{
  //test if it exists, then anihilate it
  if (texture != NULL)
  {
    SDL_DestroyTexture(texture);
    texture = NULL;
    width = 0;
    height = 0;
  }
}


void Image::render(SDL_Renderer * renderer,int x,int y,SDL_Rect * clip)
{
  //set where it renders to
  SDL_Rect renderQuad = {x,y,width,height};

  //set clip rendering dimensions
  if (clip != NULL)
  {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  //render to screen
  SDL_RenderCopy(renderer,texture,clip,&renderQuad);
}


int Image::getWidth()
{
  return width;
}


int Image::getHeight()
{
  return height;
}
