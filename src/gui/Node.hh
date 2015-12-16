#ifndef NODE_H
#define NODE_H


#include <SDL.h>


/**
 * an element of the gui system
 * The superclass of all Nodes in the gui system, this is basically the building block of
 * the gui system.
 */
class Node
{
public:
	/**
	 * sets the node's basic parameters
	 */
	Node(int offsetX,int offsetY,int width,int height):
	offsetX(offsetX),
	offsetY(offsetY),
	width(width),
	height(height)
	{};

	/**
	 * allows destruction of sub classes
	 */
	virtual ~Node()
	{};
	
	/**
	 * lets the node react to sdl events
	 * a return of 0 is considered to be normal. Anything else has some kind of special
	 * meaning depending on the node type returning it.
	 */
	virtual int onEvent(SDL_Event * e) = 0;
	//TODO: this shouldn't use sdl events, it was meant to use some special event system
	//TODO: that I will make up so that you can change the controls and also use both
	//TODO: gamepads and the keyboard and whatever else it is you desire
	
	/**
	 * displays the node
	 * displays the node on the screen. positions are relative to the parent node, or they
	 * are meant to be anyway.
	 */
	virtual void render(SDL_Renderer * renderer,int x = 0,int y = 0) = 0;
	
protected:
	int const offsetX;
	int const offsetY;
	int const width;
	int const height;
};


#endif
