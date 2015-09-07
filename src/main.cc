#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

#include <emscripten/emscripten.h>

#include "Animation.h"
#include "ImageManager.h"
#include "AnimationManager.h"
#include "SoundManager.h"
#include "Scene.h"
#include "SplashScene.h"
#include "Assets.h"


//Screen dimension constants
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;


//the window and stuff
static SDL_Window * window = NULL;
static SDL_Renderer * renderer = NULL;

//the assets
static Assets assets;

//the current scene
static Scene * scene = NULL;


bool init()
{
  //Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n",SDL_GetError());
    return false;
  }

  //Create window
  window = SDL_CreateWindow("SDL Tutorial",SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,
                             SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  //Create renderer for window
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
  if (renderer == NULL)
  {
    printf("Renderer could not be created! SDL Error: %s\n",SDL_GetError());
    return false;
  }

  //Initialize renderer color
  SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);

  //Initialize SDL_mixer
  if (Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096) == -1)
  {
    printf("couldn't initialize mixer, you nerd\n");
    return false;
  }

  return true;
}


void close()
{
  //Deallocate surface
  delete imageManager;

  //Destroy window and renderer
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  renderer = NULL;
  window = NULL;

  //Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}


void iteration()
{
  //Event handler
  SDL_Event e;

  //Handle events on queue
  while (SDL_PollEvent(&e) != 0)
  {
    //User requests quit
    if (e.type == SDL_QUIT)
    {
      close();
    }
  }

  //update the scene
  scene->update(0.01f);

  //clear the screen
  SDL_RenderClear(renderer);

  //render the scene
  scene->render(renderer);

  //update screen
  SDL_RenderPresent(renderer);
}


int main(int argc,char * * args)
{
  //Start up SDL and create window
  if(!init())
  {
    printf( "Failed to initialize!\n" );
    return 1;
  }

  //initialise the asset managers
  assets.imageManager = new ImageManager(renderer);
  assets.animationManager = new AnimationManager(imageManager);
  assets.soundManager = new SoundManager();

  //play a sound for no reason
  soundManager->play(0);

  //set the starting scene
  scene = new SplashScene();

  //start the game
  emscripten_set_main_loop(iteration,0,1);

  return 0;
}
