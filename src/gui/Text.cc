#include "Text.hh"

#include <SDL.h>


Text::Text(char const * content):
content(content)
{
	//TODO: still needs to set the normal node stuff using info from the font
}


Text::~Text()
{
	delete content;
}


int Text::onEvent(SDL_Event * e)
{
	return 0;
}


void Text::render(SDL_Renderer * renderer,int x = 0,int y = 0)
{
	erg;
}
