#include "MenuScene.hh"

#include "../assets.hh"
#include "../things/Button.hh"


int const MenuScene::PLAY_BUTTON_X = 50;
int const MenuScene::PLAY_BUTTON_Y = 50;


MenuScene::MenuScene()
{}


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
