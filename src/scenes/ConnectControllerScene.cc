#include "ConnectControllerScene.hh"


void handleEvent(SDL_Event * event)
{
	//doesn't need to get any events
	return;
}

Scene * update(float deltaTime)
{

}

void render(SDL_Renderer * renderer)
{
	SDL_RenderFillRect(renderer,{0,0,100,100});
}
