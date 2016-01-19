#include "Character.hh"


Character::Character(int xPosition,int yPosition):
xPosition(xPosition),
yPosition(yPosition)
{}


Character::~Character()
{
	//does nothing
}


void Character::update(float deltaTime)
{
	//if the character is in the process of walking, just keep on doing that

	//if the character is still make it move to it's next spot

	//if the character is meant to autorun it's script and has not yet done so it should
}


void Character::recheckEvents()
{
	bool bad = false;
	currentPage = 0;
	while(!bad)
	{
		EventPage page = pages[currentPage];

		//if this page is good to go
		if ((page.equal && (assets_vars[page.varA] == assets_vars[page.varB])) ||
			(page.less && (assets_vars[page.varA] < assets_vars[page.varB])) ||
			(page.greater && (assets_vars[page.varA] > assets_vars[page.varB])))
		{
			currentPage++;
		}

		//if this page cannot run
		else
		{
			currentPage--;
			bad = true;
		}
	}

	if (currentPage < 0)
	{
		//TODO: delete the character if this is the case, at the moment it'll just stay
		//TODO: on the first page
		currentPage = 0;
	}
}
