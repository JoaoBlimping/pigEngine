#include <stdio.h>

#include <SDL.h>

#ifdef EMSCRIPTEN
#include <emscripten/emscripten.h>
#endif


//Screen dimension constants
const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 400;


//the image that we have
SDL_Window * gWindow = NULL;
SDL_Surface * gScreenSurface = NULL;
SDL_Surface * gHelloWorld = NULL;


bool init()
{
  //Initialization flag
  bool success = true;

  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    success = false;
  }
  else
  {
    //Create window
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
      success = false;
    }
    else
    {
      //Get window surface
      gScreenSurface = SDL_GetWindowSurface( gWindow );
    }
  }
  return success;
}


bool loadMedia()
{
  //Loading success flag
  bool success = true;

  //Load splash image
  gHelloWorld = SDL_LoadBMP("assets/hey.bmp");
  if( gHelloWorld == NULL )
  {
    printf("Unable to load image! SDL Error: %s\n",SDL_GetError());
    success = false;
  }
  return success;
}

void close()
{
  //Deallocate surface
  SDL_FreeSurface( gHelloWorld );
  gHelloWorld = NULL;

  //Destroy window
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;

  //Quit SDL subsystems
  SDL_Quit();
}


int main( int argc, char* args[] )
{
  //Start up SDL and create window
  if( !init() )
  {
    printf( "Failed to initialize!\n" );
  }
  else
  {
    //Load media
    if( !loadMedia())
    {
      printf( "Failed to load media!\n" );
    }
    else
    {
      //Apply the image
      SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );

      //update the window surface
      SDL_UpdateWindowSurface(gWindow);

      //wait two seconds
      SDL_Delay( 2000 );
    }
  }

  //close SDL
  close();

  return 0;
}
