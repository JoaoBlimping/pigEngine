#ifndef WINDOW_H
#define WINDOW_H


#include "Node.hh"

#include <vector>

#include <SDL.h>


/**
 * A main window thingo that contains other gui nodes
 */
class Window:public Node
{
public:
	/**
	 * creates a window and sets it's width and height
	 */
	Window(int offsetX,int offsetY,int width,int height);

	/**
	 * deallocates the window and it's child nodes
	 */
	~Window();

	int update(float deltaTime);

	void render(SDL_Renderer * renderer,int x = 0,int y = 0);

private:
	/**
	 * vector containing all the child nodes of this window
	 */
	std::vector<Node *> children;
};

#endif