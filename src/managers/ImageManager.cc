#include "ImageManager.hh"

#include <SDL.h>

#include <iostream>
#include <fstream>

#include "../Utils.hh"

#define IMAGE_DIR "assets/images/"
#define IMAGE_LIST "assets/images/list"


using namespace std;


ImageManager::~ImageManager()
{
  //free all of the images it contains
  for (std::vector<Image *>::iterator it = images.begin();it != images.end();++it)
  {
    delete *it;
  }
}


void ImageManager::init(SDL_Renderer * renderer)
{
  //load the list of images
  ifstream list(IMAGE_LIST);

  if (!list.is_open())
  {
    printf("can't open image list\n");
    return;
  }

  char * line;

  while (list >> line)
  {
    char * filename = Utils::concatenate(IMAGE_DIR,line);

    //run the function on the filename
    Image * image = new Image();
    printf("loaded %s\n",filename);
    image->loadFromFile(renderer,filename);

    images.push_back(image);

    //deallocate the filename's memory
    delete[] filename;
  }

  list.close();
}


Image * ImageManager::getImage(int index) const
{
  return images[index];
}
