//wraps around sdl's textures to do cool shit


#ifndef IMAGE_H
#define IMAGE_H


#include <stdio.h>
#include <iostream>
#include <fstream>

#include <SDL.h>
#include <SDL_image.h>


class Image
{
public:
  //deallocates it's data and destroys it
  ~Image();

  //loads specified image file
  bool loadFromFile(SDL_Renderer * renderer,char const * filename);

  //deallocates it's data
  void free();

  //renders it at given point
  void render(SDL_Renderer * renderer,int x,int y,SDL_Rect * clip = NULL);

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


/**
 * functor for the loading of an image from a given file
 */
struct ImageLoader
{
  /**
   * loads an image from the given file
   */
  Image * operator()(char const * filename,SDL_Renderer * renderer);
};


#endif
