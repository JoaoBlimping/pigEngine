#include "creator.hh"

#include "Node.hh"
#include "Window.hh"
#include "Text.hh"
#include "Clicker.hh"


Node * creator_createTextBox(char const * content)
{
	Window * window = new Window(30,30,200,200);
	window->addChild(new Text(content));
	window->addChild(new Clicker());
	return window;
}
