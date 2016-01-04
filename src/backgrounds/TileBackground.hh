//a background made up of a tiled image


#ifndef TILE_BACKGROUND_H
#define TILE_BACKGROUND_H


#include "Background.hh"

#include <SDL2/SDL.h>

#include "../things/Image.hh"
#include "../assets.hh"
#include "../things/AbstractFactory.hh"
#include "../things/StreamReader.hh"


class TileBackground:public Background
{
public:
	/** creates the background and gives it all the things it needs */
	TileBackground(Image * pTile,float xDrift,float yDrift);

	void render(SDL_Renderer * renderer,int screenWidth,int screenHeight,float deltaTime);

private:
	/** the Image to be tiled */
	Image * tile;

	/** pixels per second that it drifts on x axis */
	float const xDrift;

	/** pixels per second that it drifts on y axis */
	float const yDrift;

	/** the tile's current x offset */
	float xOffset;

	/** the tile's current y offset */
	float yOffset;
};


/** factory that creates TileBackgrounds */
class TileBackgroundFactory:public ConcreteFactory<Background>
{
public:
	Background * operator()(StreamReader * data);
};


#endif
