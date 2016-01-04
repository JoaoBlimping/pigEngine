#include "CompoundBackground.hh"

#include "Background.hh"

#include <SDL2/SDL.h>

#include "../things/AbstractFactory.hh"
#include "../things/StreamReader.hh"
#include "backgroundFactory.hh"


CompoundBackground::CompoundBackground(Background * * contents,int nBackgrounds):
contents(contents),
nBackgrounds(nBackgrounds)
{}

CompoundBackground::~CompoundBackground()
{
	for (int i = 0;i < nBackgrounds;i++) delete contents[i];
	delete[] contents;
}

void CompoundBackground::render(SDL_Renderer * renderer,int screenWidth,int screenHeight,
								float deltaTime)
{
	for (int i = 0;i < nBackgrounds;i++)
	{
		contents[i]->render(renderer,screenWidth,screenHeight,deltaTime);
	}
}


Background * CompoundBackgroundFactory::operator()(StreamReader * data)
{
	int nBackgrounds = data->readInt();
	Background * * backgrounds = new Background * [nBackgrounds];

	for (int i = 0;i < nBackgrounds;i++)
	{
		backgrounds[i] = backgroundFactory_factory(data);
	}
	return new CompoundBackground(backgrounds,nBackgrounds);
}
