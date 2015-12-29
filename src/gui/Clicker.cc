#include "Clicker.hh"

#include "../input.hh"


#define CLICKER_WIDTH 32
#define CLICKER_HEIGHT 32


Clicker::Clicker():
Node(CLICKER_WIDTH,CLICKER_HEIGHT),
elapsed(0)
{}


int Clicker::update(float deltaTime)
{
	//click if any controller has the a button down
	for (int i = 0;i < input_N_PLAYERS;i++)
	{
		if (input_getControllerState(i)->buttons[AButton])
		{
			printf("click\n");
			return 1;
		}
	}

	return 0;
}


void Clicker::render(SDL_Renderer * renderer,int x,int y)
{
	//I dunno this probably doesn't
}
