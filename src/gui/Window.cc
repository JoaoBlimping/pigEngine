#include "Window.hh"

#include "../assets.hh"


#define WINDOW_PADDING 25
#define DELAY 2


Window::Window(int width,int height):
Node(width,height,DELAY)
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
	if (width < child->getWidth() + WINDOW_PADDING * 2)
	{
		width = child->getWidth() + WINDOW_PADDING * 2;
	}
}


int Window::logic(float deltaTime)
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
	assets_windowSkin->render(renderer,x,y,width,height);

	int yOffset = WINDOW_PADDING;
	for (std::vector<Node *>::iterator it = children.begin();it != children.end();++it)
	{
		(*it)->render(renderer,x + WINDOW_PADDING,y + yOffset);
		yOffset += (*it)->getHeight() + WINDOW_PADDING ;
	}
}
