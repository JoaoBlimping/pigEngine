#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

#include <emscripten/emscripten.h>

#include "Image.h"
#include "AssetManager.h"


//Screen dimension constants
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;


//the image that we have
SDL_Window * gWindow = NULL;
SDL_Renderer * gRenderer = NULL;
Image gBackground;
Image gImage;

//offset of the picture
int imageX = 0;
int imageY = 0;


bool init()
{
  //Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n",SDL_GetError());
    return false;
  }

  //Create window
  gWindow = SDL_CreateWindow("SDL Tutorial",SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,
                             SDL_WINDOW_SHOWN);
  if (gWindow == NULL)
  {
    printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  //Create renderer for window
  gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
  if (gRenderer == NULL)
  {
    printf("Renderer could not be created! SDL Error: %s\n",SDL_GetError());
    return false;
  }

  //Initialize renderer color
  SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);

  //initialise the asset manager
  AssetManager::init(gRenderer);

  return true;
}


bool loadMedia()
{
  //Load PNG texture
  return (gBackground.loadFromFile(gRenderer,"assets/images/texture.png") &
          gImage.loadFromFile(gRenderer,"assets/images/dany.png"));
}


void close()
{
  //Deallocate surface
  gBackground.free();
  gBackground.free();

  //Destroy window and renderer
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gRenderer = NULL;
  gWindow = NULL;

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

  //move the offset
  imageX += 1;
  imageY += 1;


  //clear the screen
  SDL_RenderClear(gRenderer);

  //Render texture to screen
  gBackground.render(gRenderer,0,0);

  //render a nice picture
  gImage.render(gRenderer,imageX,imageY);

  //update screen
  SDL_RenderPresent(gRenderer);
}


int main(int argc,char * args[])
{
  //Start up SDL and create window
  if(!init())
  {
    printf( "Failed to initialize!\n" );
    return 1;
  }

  //Load media
  if(!loadMedia())
  {
    printf( "Failed to load media!\n" );
    return 1;
  }

  emscripten_set_main_loop(iteration, 60, 1);

  return 0;
}
