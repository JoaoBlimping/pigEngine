#include "Node.hh"

#include <vector>


Node::Node(int width,int height):
width(width),
height(height)
{}


Node::~Node()
{
	for (std::vector<bool *>::iterator it = listeners.begin();it != listeners.end();++it)
	{
		**it = true;
	}
}

int Node::getWidth()
{
	return width;
}


int Node::getHeight()
{
	return height;
}


void Node::addListener(bool * target)
{
	*target = false;
	listeners.push_back(target);
}
