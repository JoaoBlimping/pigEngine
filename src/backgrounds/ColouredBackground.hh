#ifndef COLOURED_BACKGROUND_H
#define COLOURED_BACKGROUND_H


#include "Background.hh"

#include <stdint.h>
#include <iostream>

#include <SDL2/SDL.h>

#include "../assets.hh"


/** simple solid colour backround */
class ColouredBackground:public Background
{
public:
	/** creates the background and sets it's colour */
	ColouredBackground(char pRed,char pGreen,char pBlue,char pAlpha);

	virtual void update(float deltaTime);

	virtual void render(SDL_Renderer * renderer,int screenWidth,int screenHeight);

private:
	/** red component of the background colour */
	uint8_t red;

	/** green component of the background colour */
	uint8_t green;

	/** blue component of the background colour */
	uint8_t blue;
};


/** concrete factory that creates coloured backgrounds */
class ColouredBackgroundFactory:public ConcreteFactory<Background>
{
public:
	Background * operator()(std::istream * data);
};


#endif
