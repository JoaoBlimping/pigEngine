#include "input.hh"


static Controller controllers[input_N_PLAYERS];


void input_onJoyAxisEvent(SDL_JoyAxisEvent * e)
{
	if (e->axis >= NAxes) return;
	Controller * controller = controllers + e->which;
	int mappedAxis = controller->mapping.axisMapping[e->axis];
	controller->state.axes[mappedAxis] = e->value;
}


void input_onJoyButtonEvent(SDL_JoyButtonEvent * e)
{
	if (e->button >= NButtons) return;
	Controller * controller = controllers + e->which;
	int mappedButton = controller->mapping.buttonMapping[e->button];
	controller->state.buttons[mappedButton] = (e->state == SDL_PRESSED);
}


ControllerState const * input_getControllerState(int player)
{
	return &(controllers[player].state);
}


void input_setMappings(ControllerMapping * mappings)
{
	for (int i = 0;i < input_N_PLAYERS;i++)
	{
		controllers[i].mapping = mappings[i];
	}
}
