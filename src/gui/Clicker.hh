#ifndef CLICKER_H
#define CLICKER_H


#include "Node.hh"


/** a node which is used to end a set of nodes that are otherwise static */
class Clicker:public Node
{
public:
	/** creates a clicker, and initialises it's timer */
	Clicker();

	int logic(float deltaTime);

	void render(SDL_Renderer * renderer,int x = 0,int y = 0);

private:
	float elapsed;
};


#endif
