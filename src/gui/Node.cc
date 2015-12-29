#include "Node.hh"

#include <vector>


Node::Node(int width,int height,float delay):
width(width),
height(height),
delay(delay)
{}


Node::~Node()
{
	for (std::vector<bool *>::iterator it = listeners.begin();it != listeners.end();++it)
	{
		**it = true;
	}
}

void Node::addListener(bool * target)
{
	*target = false;
	listeners.push_back(target);
}

int Node::update(float deltaTime)
{
	if (delay > 0) delay -= deltaTime;
	else return logic(deltaTime);
	return 0;
}

void Node::resetDelay(float newDelay)
{
	delay = newDelay;
}

int Node::getWidth()
{
	return width;
}


int Node::getHeight()
{
	return height;
}

int Node::logic(float deltaTime)
{
	//the basic functionality is to do nothing
	return 0;
}
