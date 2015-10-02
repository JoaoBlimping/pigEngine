#include "Button.hh"

#include <SDL.h>

#include "Image.hh"



Button::Button(int pX,int pY,int const * pMouseX,int const * pMouseY,
               Image * pGraphics):
x(pX),
y(pY),
mouseX(pMouseX),
mouseY(pMouseY),
graphics(pGraphics)
{
  clip.x = 0;
  clip.y = 0;
  clip.w = graphics->getWidth() / FRAMES_TOTAL;
  clip.h = graphics->getHeight();
}


bool Button::containsMouse()
{
  return ((*mouseX >= x) && (*mouseX <= x + clip.w) &&
          (*mouseY >= y) && (*mouseY <= y + clip.h));
}


void Button::render(SDL_Renderer * renderer)
{
  //display the mouse over frame
  if (containsMouse())
  {
    clip.x = MOUSE_OVER * clip.w;
  }
  //display the mouse out frame
  else
  {
    clip.x = MOUSE_OUT * clip.w;
  }

  //now render
  graphics->render(renderer,x,y,&clip);
}
