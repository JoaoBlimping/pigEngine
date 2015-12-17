#ifndef CONTROLLER_H
#define CONTROLLER_H


/**
 * the names of all the controller axes
 * gives the names of all the controller axes, and gives them an integer value so they can
 * be used to get the right location in an array. also gives the total number of axes
 */
enum axisName
{
	LeftStickX = 0,
	LeftStickY,
	RightStickX,
	RightStickY,
	LeftTrigger,
	RightTrigger,
	NAxes
};


/**
 * the names of all the controller buttons
 * gives the names of all the controller buttons, and gives them an integer value so they
 * can be used to get the right location in an array. also gives the total number of 
 * buttons
 */
enum buttonName
{
	AButton = 0,
	BButton,
	XButton,
	YButton,
	StartButton,
	LButton,
	RButton,
	NButtons
};


/**
 * contains all info for a controller
 * Contains both the controller's current state, and also the mappings between what axis
 * sdl says things are on and what they are meant to be on
 */
typedef struct
{
	int axisMapping[NAxes];
	int buttonMapping[NButtons];
	
	float axes[NAxes];
	bool buttons[NButtons];
}
Controller;


#endif
