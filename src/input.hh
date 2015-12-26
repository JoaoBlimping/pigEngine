#ifndef INPUT_H
#define INPUT_H


#include <SDL2/SDL.h>

#include "Controller.hh"


#define N_PLAYERS 1

/**
 * called when there is a joy axis event so that the control thingo can be set
 */
void input_onJoyAxisEvent(SDL_JoyAxisEvent * e);

/**
 * called when there is a joy button event so the right button can be set
 */
void input_onJoyButtonEvent(SDL_JoyButtonEvent * e);

/**
 * gives you a specific controller set
 */
ControllerState const * input_getControllerState(int player);

/**
 * sets the button and axis mappings for all the controllers
 */
void input_setMappings(ControllerMapping * mappings);


#endif
