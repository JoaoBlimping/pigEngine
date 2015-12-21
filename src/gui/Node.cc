#include "Node.hh"


Node::Node(int offsetX,int offsetY,int width,int height):
offsetX(offsetX),
offsetY(offsetY),
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


void Node::addListener(bool * target)
{
	*target = false;
	listeners.push_back(target);
}
