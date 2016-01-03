#include "Selector.hh"

#include <vector>

#include <SDL2/SDL.h>

#include "../input.hh"
#include "../assets.hh"


#define PADDING 5
#define NODE_DELAY 0.5


Selector::Selector():
Node(0,0,NODE_DELAY),
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
	options.push_back(option);
	if (width < option->getWidth()) width = option->getWidth();
	height += option->getHeight() + PADDING;
}


int Selector::logic(float deltaTime)
{
	//click if any controller has the a button down
	for (int i = 0;i < input_N_PLAYERS;i++)
	{
		if (input_getControllerState(i)->buttons[AButton])
		{
			return selection;
		}
	}

	//move the selection up and down
	for (int i = 0;i < input_N_PLAYERS;i++)
	{
		ControllerState const * state = input_getControllerState(i);
		if (state->axes[LeftStickY] > input_AXIS_DEAD_ZONE)
		{
			selection++;
			resetDelay(NODE_DELAY);
		}
		else if (state->axes[LeftStickY] < -input_AXIS_DEAD_ZONE)
		{
			selection--;
			resetDelay(NODE_DELAY);
		}
	}


	//make sure it is within the range of the options
	if (selection < 1) selection = options.size();
	if (selection > options.size()) selection = 1;

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
			assets_selectSkin->render(renderer,x - 1,y - 1,(*it)->getWidth() + 1,
									  (*it)->getHeight() + 1);
		}

		//draw the option
		(*it)->render(renderer,x,y);
		y += (*it)->getHeight() + PADDING;

		i++;
	}
}
