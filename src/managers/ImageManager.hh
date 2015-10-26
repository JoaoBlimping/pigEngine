//manages images


#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H


#include <SDL.h>

#include <vector>

#include "../things/Image.hh"


class ImageManager
{
public:
  //some useful constants for ye
  static char const * IMAGE_DIR;
  static char const * IMAGE_LIST;

  //destroys the image manager and all of it's images
  ~ImageManager();

  //initialises the image manager and loads all it's images
  void init(SDL_Renderer * renderer);

  //gives you an item from the maneger
  Image * getImage(int index)const;

private:
  std::vector<Image *> images;
};


#endif
