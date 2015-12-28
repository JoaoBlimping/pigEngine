#include "Selector.hh"

#include <vector>

#include <SDL2/SDL.h>


Selector::~Selector()
{
	for (std::vector<Node *>::iterator it = options.begin();it != options.end();++it)
	{
		delete (*it);
	}
}


int Selector::update(float deltaTime)
{
	return 0;
}


void Selector::render(SDL_Renderer * renderer,int x,int y)
{

}
