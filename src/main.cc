#include <stdio.h>
#include <stdint.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameState.hh"
#include "scenes/Scene.hh"
#include "scenes/sceneFactory.hh"
#include "backgrounds/backgroundFactory.hh"
#include "assets.hh"
#include "input.hh"
#include "vm.hh"


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MILLI 1000

#define FIRST_SCENE "assets/scenes/start.pig"


//the game state object thing
static GameState * game = NULL;

//the window and stuff
static SDL_Window * window = NULL;
static SDL_Renderer * renderer = NULL;
static SDL_Joystick * gameController = NULL;

//false iff the game needs to close
static bool running = true;

//keeps the currentTime
static uint32_t currentTime;


bool init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n",SDL_GetError());
		return false;
	}

	//Create window
	window = SDL_CreateWindow("load game name from a file ayyy",SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,
							  SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//make it fullscreen
	//if (SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN))
	//{
	//	printf( "couldn't go fullscreen! SDL_Error: %s\n", SDL_GetError());
	//}

	//check the display mode
	SDL_DisplayMode mode;
	SDL_GetWindowDisplayMode(window,&mode);
	printf("display w:%d,h:%d\n",mode.w,mode.h);

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

	//Check for joysticks
	if (SDL_NumJoysticks() < 1)
	{
		printf("Warning: No joysticks connected!\n");
	}
	else
	{
		//Load joystick
		gameController = SDL_JoystickOpen(0);
		if (gameController == NULL)
		{
			printf("Warning: Unable to open game controller! SDL Error: %s\n",SDL_GetError());
		}
	}

	//load in the persistent assets
	assets_init(renderer,window);

	//set up the factories
	sceneFactory_init();
	backgroundFactory_init();

	//initialise the game state object thing
	game = new GameState(SCREEN_WIDTH,SCREEN_HEIGHT,sceneFactory_factory(FIRST_SCENE));

	//initialise the virtual machine
	vm_init(game);

	//get the first currentTime
	currentTime = SDL_GetTicks();

	return true;
}


void close()
{
	//delete gamestate thingo
	delete game;

	//Destroy window and renderer
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_JoystickClose(gameController);

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

	//calculatee deltaTime
	uint32_t newcurrentTime = SDL_GetTicks();
	float deltaTime = (float)(newcurrentTime - currentTime) / MILLI;
	currentTime = newcurrentTime;

	//update scene
	game->getCurrentScene()->update(deltaTime);


	//clear the screen
	SDL_RenderClear(renderer);

	//render the scene
	game->getCurrentScene()->render(renderer,deltaTime);

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
