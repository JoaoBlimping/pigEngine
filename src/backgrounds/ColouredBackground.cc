#include "ColouredBackground.hh"

#include <stdint.h>

#include <SDL2/SDL.h>

#include "../assets.hh"
#include "../things/StreamReader.hh"


ColouredBackground::ColouredBackground(uint8_t red,uint8_t green,uint8_t blue,
									   uint8_t alpha):
red(red),
green(green),
blue(blue),
alpha(alpha)
{}


void ColouredBackground::render(SDL_Renderer * renderer,int screenWidth,int screenHeight,float deltaTime)
{
	SDL_Rect fill = {0,0,screenWidth,screenHeight};
	SDL_SetRenderDrawColor(renderer,red,green,blue,alpha);
	SDL_RenderFillRect(renderer,&fill);
}


Background * ColouredBackgroundFactory::operator()(StreamReader * data)
{
	int red = data->readInt();
	int green = data->readInt();
	int blue = data->readInt();
	int alpha = data->readInt();

	return new ColouredBackground(red,green,blue,alpha);
}
