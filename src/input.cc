#include "input.hh"


static Controller controllers[N_PLAYERS];


void input_onJoyAxisEvent(SDL_JoyAxisEvent * e)
{
	Controller controller = controllers[e->which];
	int mappedAxis = controller.axisMapping[e->axis];
	controller.axes[mappedAxis] = e->value;
}


void input_onJoyButtonEvent(SDL_JoyButtonEvent * e)
{
	Controller controller = controllers[e->which];
	int mappedButton = controller.buttonMapping[e->button];
	controller.buttons[mappedButton] = e->state;
}


ControlSet const * input_getController(int player)
{
	return controllers + player;
}
