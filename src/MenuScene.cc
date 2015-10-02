#include "MenuScene.hh"

#include "Assets.hh"
#include "ImageManager.hh"
#include "Button.hh"


int const MenuScene::PLAY_BUTTON_X = 50;
int const MenuScene::PLAY_BUTTON_Y = 50;


MenuScene::MenuScene(ImageManager const * const images)
{
  int buttonImage = 4;//TODO: definetly get this into a file without delay

  playButton = new Button(PLAY_BUTTON_X,PLAY_BUTTON_Y,&mouseX,&mouseY,
                          images->getImage(buttonImage));
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


Scene * MenuScene::update(Assets const * const assets,float deltaTime)
{
  return this;
}


void MenuScene::render(Assets const * const assets,SDL_Renderer * renderer)
{
  playButton->render(renderer);
}
