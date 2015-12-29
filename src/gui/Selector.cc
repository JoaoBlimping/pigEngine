#include "Selector.hh"

#include <vector>

#include <SDL2/SDL.h>

#include "../input.hh"


#define PADDING 5


Selector::Selector():
Node(0,0),
selection(1)
{}


Selector::~Selector()
{
	for (std::vector<Node *>::iterator it = options.begin();it != options.end();++it)
	{
		delete (*it);
	}
}


void Selector::addOption(Node * option)
{
	printf("adding option\n");
	options.push_back(option);
	if (width < option->getWidth()) width = option->getWidth();
	height += option->getHeight() + PADDING;
}


int Selector::update(float deltaTime)
{
	//click if any controller has the a button down
	for (int i = 0;i < input_N_PLAYERS;i++)
	{
		if (input_getControllerState(i)->buttons[AButton])
		{
			return selection;
		}
	}
	return 0;
}


void Selector::render(SDL_Renderer * renderer,int x,int y)
{
	int i = 1;
	for (std::vector<Node *>::iterator it = options.begin();it != options.end();++it)
	{
		//draw the option backing if it is to be
		if (i == selection)
		{
			SDL_Rect drawRect = {x,y,(*it)->getWidth(),(*it)->getHeight()};
			SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0x00,0xFF);
			SDL_RenderDrawRect(renderer,&drawRect);
		}

		//draw the option
		(*it)->render(renderer,x,y);
		y += (*it)->getHeight() + PADDING;

		i++;
	}
}
