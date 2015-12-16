#include "Window.hh"


#define WINDOW_PADDING 8


Window(int offsetX,int offsetY,int width,int height):
Node(offsetX,offsetY,width,height)
{}


~Window()
{
	for (std::vector<Node *>::iterator it = children.begin();it != children.end();++it)
	{
		delete *it;
	}
}


int update(float deltaTime)
{
	for (std::vector<Node *>::iterator it = children.begin();it != children.end();++it)
	{
		int value = (*it)->update(deltaTime);
		if (value != 0) return value;
	}
	return 0;
}


void render(SDL_Renderer * renderer,int x = 0,int y = 0)
{
	erg;
}
