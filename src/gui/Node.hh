#ifndef NODE_H
#define NODE_H


#include <SDL2/SDL.h>

#include <vector>


/** an element of the gui system
 * The superclass of all Nodes in the gui system, this is basically the building block of
 * the gui system. */
class Node
{
public:
	/** sets the node's basic parameters */
	Node(int width,int height,float delay);

	/** allows destruction of sub classes */
	virtual ~Node();

	/** adds a listener to be informed when the node is deleted.
	 * It informs them by changing a boolean from false to true */
	void addListener(bool * target);

	/** does some basic stuff in the node superclass before sending off for the specific
	 * type of node's logic */
	int update(float deltaTime);

	/** reset the node's delay so that it won't do a meaningful update again for a
	 * while */
	void resetDelay(float newDelay);

	/** gives you the width of the node */
	int getWidth();

	/** gives you the height of the node */
	int getHeight();

	/** performs the node's logic
	 * it updates it for like nodes that use user input or whatever, it uses deltaTime
	 * for when you need to know the time if you actually do whatever */
	virtual int logic(float deltaTime);

	/** displays the node
	 * displays the node on the screen. positions are relative to the parent node, or they
	 * are meant to be anyway. */
	virtual void render(SDL_Renderer * renderer,int x = 0,int y = 0) = 0;

protected:
	/** the width of the node */
	int width;

	/** the height of the ndoe */
	int height;


private:
	/** list of listeners to tell when the node is deleted */
	std::vector<bool *> listeners;

	/** the amount of time this window has been going for
	 * used to make sure events don't get triggered immeadiately after the window opens */
	float delay;
};


#endif
