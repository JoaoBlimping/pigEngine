#ifndef INPUT_H
#define INPUT_H


#include <SDL.h>


#define N_PLAYERS 1


/**
 * contains all of the controls for a given player or something
 */
typedef struct
{
	/**
	 * the value of the control stick's x axis
	 */
	float leftStickX;

	/**
	 * the value of the control stick's y axis
	 */
	float leftStickY;

	/**
	 * true iff the a button is currently pressed
	 */
	bool a;

	/**
	 * true iff the b button is currently pressed
	 */
	bool b;

	/**
	 * true iff the x button is currently pressed
	 */
	bool x;

	/**
	 * true iff the y button is pressed
	 */
	bool y;

	/**
	 * true iff the z button is pressed
	 */
	bool z;

	/**
	 * true iff the start button is pressed
	 */
	bool start;

	/**
	 * true iff the select button is pressed
	 */
	bool select;

	/**
	 * true iff the l button is pressed
	 */
	bool l;

	/**
	 * true iff the r button is pressed
	 */
	bool r;
}
ControlSet;


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
ControlSet const * getController(int player);


#endif
