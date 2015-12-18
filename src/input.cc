#include "input.hh"


static Controller controllers[N_PLAYERS];


void input_onJoyAxisEvent(SDL_JoyAxisEvent * e)
{
	Controller controller = controllers[e->which];
	int mappedAxis = controller.mapping.axisMapping[e->axis];
	controller.state.axes[mappedAxis] = e->value;
}


void input_onJoyButtonEvent(SDL_JoyButtonEvent * e)
{
	Controller controller = controllers[e->which];
	int mappedButton = controller.mapping.buttonMapping[e->button];
	controller.state.buttons[mappedButton] = e->state;
}


ControllerMapping const * input_getController(int player)
{
	return &(controllers[player].mapping);
}

void input_setMappings(ControllerMapping * mappings)
{
	for (int i = 0;i < N_PLAYERS;i++)
	{
		controllers[i].mapping = mappings[i];
	}
}
