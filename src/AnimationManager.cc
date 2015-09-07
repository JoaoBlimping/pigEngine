#include "AnimationManager.h"

#include <iostream>
#include <fstream>

#include "Animation.h"
#include "ImageManager.h"
#include "Utils.h"


using namespace std;


char const * AnimationManager::ANIMATION_DIR = "assets/animations/";

char const * AnimationManager::ANIMATION_LIST = "assets/animations/list";


AnimationManager::AnimationManager(ImageManager const * const imageManager)
{
  //load the list of images
  ifstream list(ANIMATION_LIST);

  if (!list.is_open())
  {
    printf("can't open animation list\n");
    return;
  }

  char * line;

  while (list >> line)
  {
    char * filename = Utils::concatenate(ANIMATION_DIR,line);

    ifstream animFile(filename);

    if (!animFile.is_open())
    {
      printf("can't open animation file %s\n",filename);
    }

    int imageIndex;
    int frames;
    float speed;

    animFile >> imageIndex;
    animFile >> frames;
    animFile >> speed;

    animFile.close();

    //run the function on the filename
    Animation * animation = new Animation(imageManager->getImage(imageIndex),
                                          frames,speed);
    printf("loaded %s\n",filename);

    animations.push_back(animation);

    //deallocate the filename's memory
    delete[] filename;
  }

  list.close();
}


Animation * AnimationManager::getAnimation(int index)const
{
  return animations[index];
}
