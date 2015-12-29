#include "creator.hh"

#include <danylib/danylib.hh>

#include "Node.hh"
#include "Window.hh"
#include "Text.hh"
#include "Clicker.hh"
#include "Selector.hh"
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


Node * creator_createMultipleChoice(char const * question,char const * answers)
{
	Window * window = new Window(TEXT_BOX_WIDTH,TEXT_BOX_HEIGHT);
	window->addChild(new Text(TEXT_BOX_WIDTH - 20,assets_fonts.getItem(0),question));

	Selector * selector = new Selector();
	while (*answers != '~')
	{
		selector->addOption(new Text(TEXT_BOX_WIDTH - 20,assets_fonts.getItem(0),answers));
		answers = danylib_findNextString(answers);
	}
	window->addChild(selector);
	return window;
}
