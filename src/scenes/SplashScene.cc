#include "SplashScene.hh"

#include <SDL2/SDL.h>

#include "ConnectControllerScene.hh"
#include "../assets.hh"
#include "../vm.hh"


char const * SplashScene::JINGLE_FILE = "assets/internal/ebola.w8";

int const SplashScene::BACK_RED = 255;
int const SplashScene::BACK_GREEN = 128;
int const SplashScene::BACK_BLUE = 64;
int const SplashScene::BACK_ALPHA = 255;


SplashScene::SplashScene()
{
	elapsed = 0;
}


SplashScene::~SplashScene()
{}


void SplashScene::logic(float deltaTime)
{
	if (elapsed == 0)
	{
		vm_runScript(assets_scripts.getItem(0));
	}

	elapsed += deltaTime;

	assets_animations.getItem(0)->update(deltaTime);

	if (elapsed > 5)
	{
		//TODO: change to the next scene
	}
}


void SplashScene::renderContent(SDL_Renderer * renderer)
{
	//fill in the background
	SDL_SetRenderDrawColor(renderer,BACK_RED,BACK_GREEN,BACK_BLUE,BACK_ALPHA);
	SDL_RenderFillRect(renderer,NULL);

	//draw the animation
	assets_animations.getItem(0)->render(renderer,0,0);
}
