#ifndef CONTROLLER_H
#define CONTROLLER_H


/**
 * contains all of the controls for a given player or something
 */
typedef struct
{
	/** the value of the control stick's x axis */
	float leftStickX;

	/** the value of the control stick's y axis */
	float leftStickY;
	
	/** the value of the right control stick's x axis */
	float rightStickX;

	/** the value of the right control stick's y axis */
	float rightStickY;
	
	/** the value of the left trigger */
	float lTrigger;
	
	/** the value of the right trigger */
	float rTrigger;

	/** true iff the a button is currently pressed */
	bool a;

	/** true iff the b button is currently pressed */
	bool b;

	/** true iff the x button is currently pressed */
	bool x;

	/** true iff the y button is pressed */
	bool y;

	/** true iff the z button is pressed */
	bool z;

	/** true iff the start button is pressed */
	bool start;

	/** true iff the l button is pressed */
	bool l;

	/** true iff the r button is pressed */
	bool r;
	
	/** the axis number that maps to the left stick's x axis */
	int leftStickXAxisN;
	
	/** the axis number that maps to the left stick's y axis */
	int leftStickYAxisN;
	
	/** the axis number that maps to the right stick's x axis */
	int rightStickXAxisN;
	
	/** the axis number that maps to the right stick's y axis */
	int rightStickYAxisN;
	
	/** the button number that maps to the a button */
	int aButtonN;
	
	/** the button number that maps to the a button */
	int bButtonN;
	
	/** the button number that maps to the a button */
	int xButtonN;
	
	/** the button number that maps to the a button */
	int yButtonN;
	
	/** the button number that maps to the a button */
	int lButtonN;
	
	/** the button number that maps to the a button */
	int rButtonN;
}
Controller;


#endif
