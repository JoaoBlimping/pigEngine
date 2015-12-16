#include "Selector.hh"

#include <SDL.h>


Selector(int offsetX,int offsetY,int width,int height,vector<Node *> options):
Node(offsetX,offsetY,width,height),
options(options)
{}


~Selector()
{
	for (std::vector<Node *>::iterator it = options.begin();it != options.end();++it)
	{
		delete (*it);
	}
}


int onEvent(SDL_Event * e)
{
	if (e->type == SDL_KEYDOWN)
	{
		


void render(SDL_Renderer * renderer,int x = 0,int y = 0);
