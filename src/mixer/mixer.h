//a nice mixer in C that uses sdl audio


#ifndef MIXER_H
#define MIXER_H


#include <stdint.h>


//contains data a sample
typedef struct
{
  uint8_t * data;
  int len;
}mixer_Sample;

//initialises the mixer
//returns 0 iff initialisation was successful
int mixer_init(int pNChannels,int pNProtectedChannels);

//do this when you aren't going to use the mixer again
void mixer_close();

//loads a sample from a file
//returns NULL if the file wouldn't load
mixer_Sample * mixer_loadSample(char const * filename);

//frees the memory used by the given sample, sending it to hell
void mixer_freeSample(mixer_Sample * sample);

//play the sample in a free channel
void mixer_playSample(mixer_Sample * sample);

//play the sample in the requested channel
void mixer_playSampleInChannel(mixer_Sample * sample,int desiredChannel);



#endif
