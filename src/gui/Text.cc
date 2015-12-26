#include "Text.hh"

#include <SDL2/SDL.h>


Text::Text(char const * content):
Node(0,0,0,0),
content(content)
{
	//TODO: still needs to set the normal node stuff using info from the font
}


Text::~Text()
{
	delete content;
}


int Text::update(float deltaTime)
{
	return 0;
}


void Text::render(SDL_Renderer * renderer,int x,int y)
{
	//TODO: do stuff
}
