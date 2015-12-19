#include "ConnectControllerScene.hh"


Scene * ConnectControllerScene::logic(float deltaTime)
{
	//TODO: make it be able to end
	return this;
}

void ConnectControllerScene::render(SDL_Renderer * renderer)
{
	//do a nice background colour
	SDL_SetRenderDrawColor(renderer,100,100,255,255);
	SDL_RenderFillRect(renderer,NULL);

	//write some nice old text

}
