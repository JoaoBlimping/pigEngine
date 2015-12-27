#include "Window.hh"


#define WINDOW_PADDING 8


Window::Window(int width,int height):
Node(width,height)
{}


Window::~Window()
{
	for (std::vector<Node *>::iterator it = children.begin();it != children.end();++it)
	{
		delete *it;
	}
}


void Window::addChild(Node * child)
{
	children.push_back(child);
}


int Window::update(float deltaTime)
{
	for (std::vector<Node *>::iterator it = children.begin();it != children.end();++it)
	{
		int value = (*it)->update(deltaTime);
		if (value != 0) return value;
	}
	return 0;
}


void Window::render(SDL_Renderer * renderer,int x,int y)
{
	SDL_Rect shape = {x,y,width,height};
	SDL_SetRenderDrawColor(renderer,0x00,0xFF,0x00,0xFF);
	SDL_RenderFillRect(renderer,&shape);

	int yOffset = WINDOW_PADDING;
	for (std::vector<Node *>::iterator it = children.begin();it != children.end();++it)
	{
		(*it)->render(renderer,x + WINDOW_PADDING,y + yOffset);
		yOffset += (*it)->getHeight() + WINDOW_PADDING ;
	}
}
