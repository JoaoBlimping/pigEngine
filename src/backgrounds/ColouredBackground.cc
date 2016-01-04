#include "ColouredBackground.hh"

#include <stdint.h>
#include <iostream>

#include <SDL2/SDL.h>

#include "../assets.hh"


ColouredBackground::ColouredBackground(uint8_t red,uint8_t green,uint8_t blue,
									   uint8_t alpha):
red(red),
green(green),
blue(blue),
alpha(alpha)
{}


void ColouredBackground::update(float deltaTime)
{

}


void ColouredBackground::render(SDL_Renderer * renderer,int screenWidth,int screenHeight)
{
	SDL_Rect fill = {0,0,screenWidth,screenHeight};
	SDL_SetRenderDrawColor(renderer,red,green,blue,alpha);
	SDL_RenderFillRect(renderer,&fill);
}


Background * ColouredBackgroundFactory::operator()(std::istream * data)
{
	int red;
	int green;
	int blue;
	int alpha;

	data->operator>>(red);
	data->operator>>(green);
	data->operator>>(blue);
	data->operator>>(alpha);

	return new ColouredBackground(red,green,blue,alpha);
}
