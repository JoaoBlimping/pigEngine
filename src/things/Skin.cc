#include "Skin.hh"

#include <SDL2/SDL.h>

#include "Image.hh"


Skin::Skin(Image * image):
image(image)
{}


void Skin::render(SDL_Renderer * renderer,int x,int y,int width,int height)
{
	SDL_Rect clip = {0,0,image->getWidth() / 3,image->getHeight() / 3};

	//fill the whole thing with the middle part
	clip.x = clip.w;
	clip.y = clip.h;

	for (int tX = 1;tX < width / clip.w;tX++)
	{
		for (int tY = 1;tY < height / clip.h;tY++)
		{
			image->render(renderer,x + tX * clip.w,y + tY * clip.h,&clip);
		}
	}

	//draw top left corner
	clip.x = 0;
	clip.y = 0;
	image->render(renderer,x,y,&clip);

	//draw top border
	clip.x = clip.w;
	for (int tX = 1;tX < width / clip.w;tX++)
	{
		image->render(renderer,x + tX * clip.w,y,&clip);
	}

	//draw left border
	clip.x = 0;
	clip.y = clip.h;
	for (int tY = 1;tY < height / clip.h;tY++)
	{
		image->render(renderer,x,y + tY * clip.h,&clip);
	}

	//draw top right corner
	clip.x = clip.w * 2;
	clip.y = 0;
	image->render(renderer,x + width - clip.w,y,&clip);

	//draw bottom left corner
	clip.x = 0;
	clip.y = clip.h * 2;
	image->render(renderer,x,y + height - clip.h,&clip);

	//draw bottom border
	clip.x = clip.w;
	for (int tX = 1;tX < width / clip.w;tX++)
	{
		image->render(renderer,x + tX * clip.w,y + height - clip.h,&clip);
	}

	//draw right border
	clip.x = clip.w * 2;
	clip.y = clip.h;
	for (int tY = 1;tY < height / clip.h;tY++)
	{
		image->render(renderer,x + width - clip.w,y + tY * clip.h,&clip);
	}

	//draw bottom right corner
	clip.y = clip.h * 2;
	image->render(renderer,x + width - clip.w,y + height - clip.h,&clip);
}
