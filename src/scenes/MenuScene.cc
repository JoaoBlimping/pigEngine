#include "MenuScene.hh"

#include "../assets.hh"
#include "../things/Button.hh"


int const MenuScene::PLAY_BUTTON_X = 50;
int const MenuScene::PLAY_BUTTON_Y = 50;


MenuScene::MenuScene()
{
  int buttonImage = 4;//TODO: definetly get this into a file without delay

  playButton = new Button(PLAY_BUTTON_X,PLAY_BUTTON_Y,&mouseX,&mouseY,
                          assets_images.getItem(buttonImage));
}


MenuScene::~MenuScene()
{
  delete playButton;
}


void MenuScene::handleEvent(SDL_Event * event)
{
  //mouse movement
  if (event->type == SDL_MOUSEMOTION)
  {
    SDL_GetMouseState(&mouseX,&mouseY);
  }
}


Scene * MenuScene::update(float deltaTime)
{
  return this;
}


void MenuScene::render(SDL_Renderer * renderer)
{
  playButton->render(renderer);
}
