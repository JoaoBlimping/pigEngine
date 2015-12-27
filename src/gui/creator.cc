#include "creator.hh"

#include "Node.hh"
#include "Window.hh"
#include "Text.hh"
#include "Clicker.hh"
#include "../assets.hh"


#define TEXT_BOX_WIDTH 400
#define TEXT_BOX_HEIGHT 200


Node * creator_createTextBox(char const * content)
{
	Window * window = new Window(TEXT_BOX_WIDTH,TEXT_BOX_HEIGHT);
	window->addChild(new Text(TEXT_BOX_WIDTH - 20,assets_fonts.getItem(0),content));
	window->addChild(new Clicker());
	return window;
}
