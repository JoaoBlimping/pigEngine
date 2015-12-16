#include "input.hh"


static ControlSet controllers[N_PLAYERS];


void input_onJoyAxisEvent(SDL_JoyAxisEvent * e)
{
	//TODO: actually do stuff here
}


void input_onJoyButtonEvent(SDL_JoyButtonEvent * e)
{
	//TODO: actually do stuff here
}


ControlSet const * getController(int player)
{
	return controllers + player;
}
