#include "Text.hh"

#include <SDL2/SDL.h>


Text::Text(int width,Font * font,char const * content):
Node(width,font->getStringHeight(content,width),-1),
font(font),
content(content)
{}


void Text::render(SDL_Renderer * renderer,int x,int y)
{
	font->renderString(renderer,content,x,y,width);
}
