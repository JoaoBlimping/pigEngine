#include "Button.h"



Button(int pX,int pY,int const * pMouseX,int const * pMouseY,Image * pImage):
x(pX),
y(pY),
mouseX(pMouseX),
mouseY(pMouseY),
image(pImage)
{
  clip.x = 0;
  clip.y = 0;
  clip.w = image->getWidth() / FRAMES_TOTAL;
  clip.h = image->getHeight();
}


bool containsMouse()
{
  return ((*mouseX >= x) && (*mouseX <= x + clip.w) &&
          (*mouseY >= y) && (*mouseY <= y + clip.h));
}


void render(SDL_Renderer * renderer)
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
  image->render(renderer,x,y,&clip);
}
