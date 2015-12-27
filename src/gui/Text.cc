#include "Text.hh"

#include <SDL2/SDL.h>


Text::Text(int width,Font * font,char const * content):
Node(width,font->getStringHeight(content,width)),
font(font),
content(content)
{}


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
	font->renderString(renderer,content,x,y,width);
}
