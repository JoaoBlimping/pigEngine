#include "ConnectControllerScene.hh"


void ConnectControllerScene::handleEvent(SDL_Event * event)
{
	//doesn't need to get any events
	return;
}

Scene * ConnectControllerScene::update(float deltaTime)
{
	//TODO: make it be able to end
	return this;
}

void ConnectControllerScene::render(SDL_Renderer * renderer)
{
	SDL_Rect screen;
	screen.x = 0;
	screen.y = 0;
	screen.w = 100;
	screen.h = 100;
	SDL_RenderFillRect(renderer,&screen);
}
