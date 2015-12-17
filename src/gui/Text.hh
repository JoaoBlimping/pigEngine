#ifndef TEXT_H
#define TEXT_H


#include "Node.hh"

#include <SDL.h>


/**
 * statically displays text
 * A node that simply displays a set piece of text and doesn't do anything else of
 * interest
 */
class Text:public Node
{
public:
	/**
	 * create the text object with it's text that it displays
	 * sets the node's width and height based on the amount of text that it contains
	 */
	Text(char const * content);

	/**
	 * deletes the contained text
	 */
	~Text();

	int update(float deltaTime);

	void render(SDL_Renderer * renderer,int x = 0,int y = 0);

private:
	/**
	 * the actual text that this node contains
	 */
	char const * content;
};


#endif
