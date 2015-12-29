#ifndef TEXT_H
#define TEXT_H


#include "Node.hh"
#include "../things/Font.hh"

#include <SDL2/SDL.h>


/** statically displays text
 * A node that simply displays a set piece of text and doesn't do anything else of
 * interest */
class Text:public Node
{
public:
	/** create the text object with it's text that it displays
	 * sets the node's height based on the amount of text that it contains, note that
	 * content is constant, and so cannot be taken responsibility for by the text class */
	Text(int width,Font * font,char const * content);

	void render(SDL_Renderer * renderer,int x = 0,int y = 0);

private:
	/** the actual text that this node contains
	 * Text is not responsible for deleting it's text*/
	char const * content;

	/** the font that it uses to render itself */
	Font * font;
};


#endif
