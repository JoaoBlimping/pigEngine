#include "MenuScene.h"



int const PLAY_BUTTON_X = 0;
int const PLAY_BUTTON_Y = 0;


MenuScene(ImageManager const * const images)
{
  int buttonImage = 5;//TODO: definetly get this into a file without delay

  playButton = new Button(PLAY_BUTTON_X,PLAY_BUTTON_Y,&mouseX,&mouseY,
                          images->getImage(buttonImage));
}


~MenuScene()
{
  delete button;
}


void handleEvent(SDL_Event * event)
{
  //mouse movement
  if (event->type == SDL_MOUSEMOTION)
  {
    SDL_GetMouseState(&mouseX,&mouseY);
  }
}


Scene * update(Assets const * const assets,float deltaTime)
{

}


void render(Assets const * const assets,SDL_Renderer * renderer)
{

}
