#include "SoundManager.hh"

#include <SDL/SDL_mixer.h>

#include <iostream>
#include <fstream>
#include <stdio.h>

#include "Utils.hh"

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
    Mix_Chunk * sound = Mix_LoadWAV(filename);
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
  for (std::vector<Mix_Chunk *>::iterator it = sounds.begin();
       it != sounds.end();++it)
  {
    Mix_FreeChunk(*it);
  }
}


void SoundManager::play(int sound)
{
  Mix_PlayChannel(-1,sounds[sound],0);
}
