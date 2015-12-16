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
	 * updates the node
	 * it updates it for like nodes that use user input or whatever, it uses deltaTime
	 * for when you need to know the time if you actually do whatever
	 */
	virtual int update(float deltaTime) = 0;

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
