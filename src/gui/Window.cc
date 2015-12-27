#include "Window.hh"


#define WINDOW_PADDING 8


Window::Window(int offsetX,int offsetY,int width,int height):
Node(offsetX,offsetY,width,height)
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
	//TODO: do actual graphics
}
