#ifndef SELECTOR_H
#define SELECTOR_H


#include "Node.hh"

#include <SDL2/SDL.h>

#include <vector>


/** lets you select a Node from a selection of nodes */
class Selector:public Node
{
public:
	/** creates the selector and sets it's basic node attributes */
	Selector();

	/** deletes it's options */
	~Selector();

	/** adds an option to the selector's options, possibly resizing it in the process
	 * by adding a node to this as an option, the selector takes ownership of it, so
	 * deallocation of it will happen here when the selector gets deleted */
	void addOption(Node * option);

	int update(float deltaTime);

	void render(SDL_Renderer * renderer,int x = 0,int y = 0);

private:
	/** all of the options for selection which are all nodes */
	std::vector<Node *> options;

	/** the currently selected option */
	int selection;
};


#endif
