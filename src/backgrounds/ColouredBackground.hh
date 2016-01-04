#ifndef COLOURED_BACKGROUND_H
#define COLOURED_BACKGROUND_H


#include "Background.hh"

#include <stdint.h>
#include <iostream>

#include <SDL2/SDL.h>

#include "../assets.hh"
#include "../things/AbstractFactory.hh"


/** simple solid colour backround */
class ColouredBackground:public Background
{
public:
	/** creates the background and sets it's colour */
	ColouredBackground(uint8_t red,uint8_t green,uint8_t blue,uint8_t alpha);

	virtual void update(float deltaTime);

	virtual void render(SDL_Renderer * renderer,int screenWidth,int screenHeight);

private:
	/** red component of the background colour */
	uint8_t red;

	/** green component of the background colour */
	uint8_t green;

	/** blue component of the background colour */
	uint8_t blue;

	/** alpha component of the background colour */
	uint8_t alpha;
};


/** concrete factory that creates coloured backgrounds */
class ColouredBackgroundFactory:public ConcreteFactory<Background>
{
public:
	Background * operator()(std::istream * data);
};


#endif
