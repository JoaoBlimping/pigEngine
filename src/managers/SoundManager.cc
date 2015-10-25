#include "SoundManager.hh"

#include <iostream>
#include <fstream>
#include <stdio.h>

#include "../Utils.hh"
#include "../mixer/mixer.hh"

using namespace std;


char const * SoundManager::SOUND_DIR = "assets/sounds/";

char const * SoundManager::SOUND_LIST = "assets/sounds/list";


SoundManager::SoundManager()
{
  //load the list of images
  ifstream list(SOUND_LIST);

  if (!list.is_open())
  {
    printf("can't open sound list\n");
    return;
  }

  char * line;

  while (list >> line)
  {
    char * filename = Utils::concatenate(SOUND_DIR,line);
    mixer_Sample * sound = mixer_loadSample(filename);
    if (sound != NULL)
    {
      printf("loaded %s\n",filename);
    }

    sounds.push_back(sound);

    //deallocate the filename's memory
    delete[] filename;
  }

  list.close();
}


SoundManager::~SoundManager()
{
  for (std::vector<mixer_Sample *>::iterator it = sounds.begin();
       it != sounds.end();++it)
  {
    mixer_freeSample(*it);
  }
}


void SoundManager::play(int sound)
{
  mixer_playSample(sounds[sound]);
}
