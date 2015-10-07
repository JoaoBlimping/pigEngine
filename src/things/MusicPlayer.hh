//a music player that puts music into sdl with magic


#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H


#include <stdint.h>


class MusicPlayer
{
public:
  MusicPlayer();

private:
  //this is what actually puts the music in the buffer
  static void playMusic(void * udata,uint8_t * stream,int len);

  //this is the point that the music is up to
  int musicPos;
};


#endif
