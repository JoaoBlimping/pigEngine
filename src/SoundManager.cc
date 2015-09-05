#include "SoundManager.h"

#include <SDL/SDL_mixer.h>

#include <stdio.h>


SoundManager::SoundManager()
{
  char * filename = "assets/sounds/pingaz.wav";

  pingaz = Mix_LoadWAV(filename);
  if (pingaz == NULL)
  {
    printf("sound file %s didn't load\n",filename);
  }

}


SoundManager::~SoundManager()
{
  Mix_FreeChunk(pingaz);
}


void SoundManager::play()
{
  Mix_PlayChannel(-1,pingaz,0);
}
