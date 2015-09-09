#include "SplashScene.h"

#include <SDL.h>


char const * SplashScene::JINGLE_FILE = "assets/internal/jingle.wav";

int const SplashScene::BACK_RED = 255;
int const SplashScene::BACK_GREEN = 128;
int const SplashScene::BACK_BLUE = 64;
int const SplashScene::BACK_ALPHA = 255;


SplashScene::SplashScene()
{
  //default the elapsed time to 0
  elapsed = 0;

  //load in the sound jingle
  Mix_Chunk * jingle = Mix_LoadWAV(JINGLE_FILE);
  if (jingle == NULL)
  {
    printf("failed to load sound %s\n",JINGLE_FILE);
  }
  else
  {
    Mix_PlayChannel(-1,jingle,0);
  }
}


SplashScene::~SplashScene()
{
  Mix_FreeChunk(jingle);
}


Scene * SplashScene::update(Assets const * const assets,float deltaTime)
{
  elapsed += deltaTime;

  assets->animations->getAnimation(0)->update(deltaTime);

  if (Mix_Playing(-1) == 0)
  {
    return NULL;//TODO: make it return the menu scene
  }
  else
  {
    return this;
  }
}


void SplashScene::render(Assets const * const assets,SDL_Renderer * renderer)
{
  //fill in the background
  SDL_SetRenderDrawColor(renderer,BACK_RED,BACK_GREEN,BACK_BLUE,BACK_ALPHA);
  SDL_RenderFillRect(renderer,NULL);

  //draw the animation
  assets->animations->getAnimation(0)->render(renderer,0,0);
}
