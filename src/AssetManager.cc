#include "AssetManager.h"

#include <iostream>
#include <fstream>

#include "Utils.h"


using namespace std;


char const * AssetManager::ANIMATION_DIR = "assets/animations/";
char const * AssetManager::ANIMATION_LIST = "assets/animations/list";
char const * AssetManager::IMAGE_DIR = "assets/images/";
char const * AssetManager::IMAGE_LIST = "assets/images/list";


void AssetManager::init(SDL_Renderer * renderer)
{
  //load the list of images
  ifstream imageList(IMAGE_LIST);

  char * line;

  if (!imageList.is_open())
  {
    printf("can't open image list\n");
    return;
  }

  while (imageList >> line)
  {
    char * filename = Utils::concatenate(IMAGE_DIR,line);

    //load the image
    Image * image = new Image();
    image->loadFromFile(renderer,filename);

    //deallocate the filename's memory
    delete[] filename;
  }

  imageList.close();
}
