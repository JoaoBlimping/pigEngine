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
	Node(int offsetX,int offsetY,int width,int height);

	/** allows destruction of sub classes */
	virtual ~Node();

	/** adds a listener to be informed when the node is deleted.
	 * It informs them by changing a boolean from false to true */
	void addListener(bool * target);

	/** updates the node
	 * it updates it for like nodes that use user input or whatever, it uses deltaTime
	 * for when you need to know the time if you actually do whatever */
	virtual int update(float deltaTime) = 0;

	/** displays the node
	 * displays the node on the screen. positions are relative to the parent node, or they
	 * are meant to be anyway. */
	virtual void render(SDL_Renderer * renderer,int x = 0,int y = 0) = 0;

protected:
	/** the relative left position the node */
	int const offsetX;

	/** the relative top position on the node */
	int const offsetY;

	/** the width of the node */
	int const width;

	/** the height of the ndoe */
	int const height;


private:
	/** list of listeners to tell when the node is deleted */
	std::vector<bool *> listeners;
};


#endif
