#include "AnimationManager.hh"

#include <iostream>
#include <fstream>

#include "ImageManager.hh"
#include "../things/Animation.hh"
#include "../Utils.hh"


#define ANIMATION_DIR "assets/animations/"
#define ANIMATION_LIST "assets/animations/list"


using namespace std;


void AnimationManager::init(ImageManager const * const images)
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
    Animation * animation = new Animation(images->getImage(imageIndex),
                                          frames,speed);
    printf("loaded %s\n",filename);

    animations.push_back(animation);

    //deallocate the filename's memory
    delete[] filename;
  }

  list.close();

}


Animation * AnimationManager::getAnimation(int index) const
{
  return animations[index];
}
