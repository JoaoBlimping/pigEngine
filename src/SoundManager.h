//manages sounds n stufffffff


#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H


#include <SDL/SDL_mixer.h>


class SoundManager
{
public:
  //creates all of the sounds in the sound directory
  SoundManager();

  //deletes all of the sounds
  ~SoundManager();

  //plays a sexy sound
  void play();

private:
  Mix_Chunk * pingaz;
};


#endif
