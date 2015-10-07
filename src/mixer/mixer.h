//a nice mixer in C that uses sdl audio


#ifndef MIXER_H
#define MIXER_H


//contains data a sample
struct mixer_Sample
{
  uint8_t * data;
  int len;
};

//initialises the mixer
//returns true iff initialisation was successful
bool mixer_init();

//loads a sample from a file
mixer_Sample * mixer_loadSample(char const * filename);



#endif
