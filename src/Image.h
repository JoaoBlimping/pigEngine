//wraps around sdl's textures to do cool shit


#ifndef IMAGE_H
#define IMAGE_H


#include <SDL.h>
#include <SDL_image.h>


class Image
{
public:
  //deallocates it's data and destroys it
  ~Image();

  //loads specified image file
  bool loadFromFile(char const * filename);

  //deallocates it's data
  void free();

  //renders it at given point
  void render(SDL_Renderer const * renderer,int x,int y,SDL_Rect * clip = NULL);

  //accessors for image dimensions
  int getWidth();
  int getHeight();

private:
  //the sdl texture
  SDL_Texture * texture;

  //the image's dimensions
  int width;
  int height;
};


#endif