#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

#include <emscripten/emscripten.h>


//Screen dimension constants
const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 400;


//the image that we have
SDL_Window * gWindow = NULL;
SDL_Renderer * gRenderer = NULL;
SDL_Texture * gTexture = NULL;

//offset of the picture


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

  return true;
}


SDL_Texture * loadTexture(char const * path)
{
  //The final texture
  SDL_Texture* newTexture = NULL;

  //Load image at specified path
  SDL_Surface * loadedSurface = IMG_Load(path);
  if (loadedSurface == NULL)
  {
    printf("Unable to load image %s! SDL_image Error: %s\n", path,IMG_GetError());
    return NULL;
  }

  //Create texture from surface pixels
  newTexture = SDL_CreateTextureFromSurface(gRenderer,loadedSurface);
  if (newTexture == NULL)
  {
    printf("Unable to create texture from %s! SDL Error: %s\n",path,SDL_GetError());
  }

  //Get rid of old loaded surface
  SDL_FreeSurface(loadedSurface);

  return newTexture;
}


bool loadMedia()
{
  //Load PNG texture
  gTexture = loadTexture("assets/texture.png");

  if(gTexture == NULL)
  {
    printf("Failed to load texture image!\n");
    return false;
  }
  return true;
}


void close()
{
  //Deallocate surface
  SDL_DestroyTexture(gTexture);
  gTexture = NULL;

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


  //clear the screen
  SDL_RenderClear(gRenderer);

  //Render texture to screen
  SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);

  //update screen
  SDL_RenderPresent(gRenderer);

}


int main( int argc, char* args[] )
{
  //Start up SDL and create window
  if(!init())
  {
    printf( "Failed to initialize!\n" );
  }
  else
  {
    //Load media
    if(!loadMedia())
    {
      printf( "Failed to load media!\n" );
    }
    else
    {
      emscripten_set_main_loop(iteration, 60, 1);
    }
  }

  return 0;
}
