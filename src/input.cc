#include "input.hh"


static ControlSet controllers[N_PLAYERS];


void input_onJoyAxisEvent(SDL_JoyAxisEvent * e)
{
	erg;
}


void input_onJoyButtonEvent(SDL_JoyButtonEvent * e)
{
	erg;
}


ControlSet const * getController(int player)
{
	return controllers[player];
}
