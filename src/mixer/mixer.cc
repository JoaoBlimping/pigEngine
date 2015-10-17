#include "mixer.hh"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <SDL.h>


//the sample rate of the audio
static int const FREQ = 22050;

//the format of the audio
static uint16_t const FORMAT = AUDIO_S8;

//the number of sound channels
static uint8_t const CHANNELS = 2;

//size of the audio buffer
static uint16_t const SAMPLES = 1024;

static int const SAMPLE_COUNTER_LENGTH = 4;


//a channel that plays a sound
typedef struct
{
  //the sample that it plays
  mixer_Sample * sample;

  //the position in the sample that has been reached
  int position;
}Channel;


//things the mixer must remember
static int nChannels;
static int nProtectedChannels;
static Channel * channels;


//the function that puts the audio into the audio buffer
static void fillAudio(void * udata,uint8_t * stream,int len)
{
  //mix in as much as we can for each channel
  for (int i = 0;i < nChannels;i++)
  {
    //don't try to play empty channels
    if (channels[i].sample == NULL)
    {
      continue;
    }

    //add the shorter of remaining sample length or buffer length
    int remainingLength = channels[i].sample->len - channels[i].position;
    if (remainingLength < len)
    {
      len = remainingLength;
    }

    //SDL_MixAudio(stream,channels[i].sample->data,len,SDL_MIX_MAXVOLUME);
    for (int o = 0;o < len;o += 2)
    {
      stream[o] += channels[i].sample->left[channels[i].position + o];
      stream[o + 1] += channels[i].sample->right[channels[i].position + o];
    }

    //put the channel's progress forward
    channels[i].position += len;

    //delete it if it's done
    if (channels[i].position >= channels[i].sample->len - 1)
    {
      channels[i].sample = NULL;
    }
  }
}


int mixer_init(int pNChannels,int pNProtectedChannels)
{
  nChannels = pNChannels;
  nProtectedChannels = pNProtectedChannels;

  //allocate the channels
  channels = (Channel *)malloc(sizeof(Channel) * nChannels);

  //give them starter values
  for (int i = 0;i < nChannels;i++)
  {
    channels[i].sample = NULL;
    channels[i].position = 0;
  }

  //set up the actual audio player
  SDL_AudioSpec wanted;

  wanted.freq = FREQ;
  wanted.format = FORMAT;
  wanted.channels = CHANNELS;
  wanted.samples = SAMPLES;
  wanted.callback = fillAudio;
  wanted.userdata = NULL;

  //now open it
  if (SDL_OpenAudio(&wanted,NULL) < 0)
  {
    printf("Couldn't open audio: %s\n",SDL_GetError());
    return(-1);
  }

  //and begin immeadiately
  SDL_PauseAudio(0);

  return 0;
}


void mixer_close()
{
  free(channels);
}


mixer_Sample * mixer_loadSample(char const * filename)
{
  FILE * inputFile = fopen(filename,"rb");

  //test that the file is open
  if (inputFile == NULL)
  {
    printf("can't open w8 file %s\n",filename);
    return NULL;
  }

  //read the length of the sample which is in multiple bytes
  uint32_t length = 0;

  length |= getc(inputFile);
  length |= getc(inputFile) << 8;
  length |= getc(inputFile) << 16;
  length |= getc(inputFile) << 24;


  printf("filename is %s, length is %d\n",filename,length);

  //create the empty sample
  mixer_Sample * sample = new mixer_Sample;
  sample->left = new uint8_t[length];
  sample->right = new uint8_t[length];
  sample->len = length;

  //fill it with data from the file
  for (int i = 0;i < length * 2;i += 2)
  {
    sample->left[i] = getc(inputFile);
    sample->right[i + 1] = getc(inputFile);
  }

  //close the file
  fclose(inputFile);

  return sample;
}


void mixer_freeSample(mixer_Sample * sample)
{
  //kills it's data before turning the gun upon itself
  delete sample->left;
  delete sample->right;
  delete sample;
}


void mixer_playSample(mixer_Sample * sample)
{
  for (int i = nProtectedChannels;i < nChannels;i++)
  {
    if (channels[i].sample == NULL)
    {
      channels[i].sample = sample;
      channels[i].position = 0;
    }
  }
}


void mixer_playSampleInChannel(mixer_Sample * sample,int desiredChannel)
{
  channels[desiredChannel].sample = sample;
  channels[desiredChannel].position = 0;
}
