#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

#include <emscripten/emscripten.h>

#include "scenes/Scene.hh"
#include "scenes/SplashScene.hh"
#include "assets.hh"


//Screen dimension constants
int const SCREEN_WIDTH = 480;
int const SCREEN_HEIGHT = 640;

//the window and stuff
static SDL_Window * window = NULL;
static SDL_Renderer * renderer = NULL;

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

	//Initialize mixer
	//TODO: use the real mixer

	return true;
}


void close()
{
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

		//a controller axis changes
		else if (e.type == SDL_JOYAXISMOTION)
		{
			input_onJoyAxisEvent(&e);
		}

		//a controller button changes
		else if (e.type == SDL_JOYBUTTON)
		{
			input_onJoyButtonEvent(&e);
		}

		//any other event is sent to the current scene
		else
		{
			scene->handleEvent(&e);
		}
	}

	//update the scene
	Scene * newScene = scene->update(0.01f);//TODO: actually calculate delta time

	if (newScene != scene)
	{
		delete scene;
		scene = newScene;
	}

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

	//load in the persistent assets
	assets_init(renderer);

	//set the starting scene
	scene = new SplashScene();

	//start the game
	emscripten_set_main_loop(iteration,0,1);

	return 0;
}
