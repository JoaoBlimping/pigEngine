#ifndef COMPOUND_BACKGROUND_H
#define COMPOUND_BACKGROUND_H


#include "Background.hh"

#include <SDL2/SDL.h>

#include "../things/AbstractFactory.hh"
#include "../things/StreamReader.hh"


/** background that is made up of a bunch of backgrounds and shows them all */
class CompoundBackground:public Background
{
public:
	/** creates the background and gives it it's inner backgrounds and the number of
	 * them */
	CompoundBackground(Background * * contents,int nBackgrounds);

	/** deletes the inner backgrounds */
	~CompoundBackground();

	void render(SDL_Renderer * renderer,int screenWidth,int screenHeight,float deltaTime);

private:
	/** the backgrounds that make it up */
	Background * * contents;

	/** the number of backgrounds it has */
	int nBackgrounds;
};


/** factory that creates compound backgrounds */
class CompoundBackgroundFactory:public ConcreteFactory<Background>
{
public:
	Background * operator()(StreamReader * data);
};


#endif
