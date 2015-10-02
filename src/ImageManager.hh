//manages images


#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H


#include <SDL.h>

#include <vector>

#include "Image.hh"


class ImageManager
{
public:
  //some useful constants for ye
  static char const * IMAGE_DIR;
  static char const * IMAGE_LIST;

  //creates a fresh new image manager just for you <3
  ImageManager(SDL_Renderer * renderer);

  //destroys the image manager and all of it's images
  ~ImageManager();

  //gives you an item from the maneger
  Image * getImage(int index)const;

private:
  std::vector<Image *> images;
};


#endif
