#include "Selector.hh"

#include <vector>

#include <SDL.h>


Selector(int offsetX,int offsetY,int width,int height,std::vector<Node *> options):
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


int update(float deltaTime)
{
	return 0;
}


void render(SDL_Renderer * renderer,int x = 0,int y = 0)
{

}
