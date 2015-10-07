#include "MusicPlayer.hh"


#include <stdint.h>

#include <SDL.h>


MusicPlayer::MusicPlayer()
{
  musicPos = 0;
}


void MusicPlayer::playMusic(void * udata,uint8_t * stream,int len)
{
  int pos = *(int*)udata;

  for(int i = 0;i < len;i++)
  {
    stream[i] = (i+pos) & 0xFF;
  }

  //set the pos for next time
  pos+=len;
  *(int*)udata = pos;
}
