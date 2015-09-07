//manages sounds n stufffffff


#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H


#include <vector>

#include <SDL/SDL_mixer.h>


class SoundManager
{
public:
  //locations of important sound related files
  static char const * SOUND_DIR;
  static char const * SOUND_LIST;

  //creates all of the sounds in the sound directory
  SoundManager();

  //deletes all of the sounds
  ~SoundManager();

  //plays a sexy sound
  void play(int sound);

private:
  //contains all of the sounds
  std::vector<Mix_Chunk *> sounds;
};


#endif
