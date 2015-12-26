#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameState.hh"
#include "scenes/Scene.hh"
#include "scenes/SplashScene.hh"
#include "assets.hh"
#include "input.hh"
#include "addons.hh"


//the game state object thing
static GameState * game = NULL;

//the window and stuff
static SDL_Window * window = NULL;
static SDL_Renderer * renderer = NULL;

//false iff the game needs to close
static bool running = true;

bool init()
{
	//then the next fun thing to do is to initialise the game state object thing
	//TODO: this will come from a factory using a file, so magic numbers can be
	//TODO: temporarily forgiven
	game = new GameState(640,480,new SplashScene());

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n",SDL_GetError());
		return false;
	}

	//Create window
	window = SDL_CreateWindow("SDL Tutorial",SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED,game->screenWidth,game->screenHeight,
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

	//initialise the input with the basic input. TODO:perhaps make this nicer
	ControllerMapping playerMapping;
	playerMapping.axisMapping[LeftStickX] = 0;
	playerMapping.axisMapping[LeftStickY] = 1;
	playerMapping.axisMapping[RightStickX] = 2;
	playerMapping.axisMapping[RightStickY] = 3;
	playerMapping.axisMapping[LeftTrigger] = 4;
	playerMapping.axisMapping[RightTrigger] = 5;
	playerMapping.buttonMapping[AButton] = 0;
	playerMapping.buttonMapping[BButton] = 1;
	playerMapping.buttonMapping[XButton] = 2;
	playerMapping.buttonMapping[YButton] = 3;
	playerMapping.buttonMapping[LButton] = 4;
	playerMapping.buttonMapping[RButton] = 5;
	playerMapping.buttonMapping[StartButton] = 6;
	input_setMappings(&playerMapping);

	//now set up the virtual machine and that
	//addons_addAddons(game,&assets_vm);

	//load in the persistent assets
	assets_init(renderer);

	return true;
}


void close()
{
	//delete gamestate thingo
	delete game;

	//Destroy window and renderer
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	//turn running off
	running = false;
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
			return;
		}

		//a controller axis changes
		else if (e.type == SDL_JOYAXISMOTION)
		{
			input_onJoyAxisEvent(&e.jaxis);
		}

		//a controller button changes
		else if (e.type == SDL_JOYBUTTONDOWN || e.type == SDL_JOYBUTTONUP)
		{
			input_onJoyButtonEvent(&e.jbutton);
		}
	}

	//update the scene
	//TODO: actually calculate delta time
	game->getCurrentScene()->update(0.01f);

	//clear the screen
	SDL_RenderClear(renderer);

	//render the scene
	game->getCurrentScene()->render(renderer);

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

	//running the game
	while (running) iteration();

	return 0;
}
