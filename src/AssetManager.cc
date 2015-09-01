#include "AssetManager.h"

#include <iostream>
#include <fstream>


using namespace std;


void AssetManager::init()
{
  //load the images
  ifstream imageList;
  imageList.open(IMAGE_DIR + LIST,ios::in);
  char * line;
  if (imageList.is_open())
  {
    while (getline(imageList,line))
    {
      printf("hey %s\n",line);
    }
  }

}
