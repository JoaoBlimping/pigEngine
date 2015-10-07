#include "MenuScene.hh"

#include "Assets.hh"
#include "ImageManager.hh"
#include "things/Button.hh"
#include "things/MusicPlayer.hh"


int const MenuScene::PLAY_BUTTON_X = 50;
int const MenuScene::PLAY_BUTTON_Y = 50;


MenuScene::MenuScene(ImageManager const * const images)
{
  int buttonImage = 4;//TODO: definetly get this into a file without delay

  playButton = new Button(PLAY_BUTTON_X,PLAY_BUTTON_Y,&mouseX,&mouseY,
                          images->getImage(buttonImage));

  //load the music
  music = new MusicPlayer();
}


MenuScene::~MenuScene()
{
  delete playButton;
  delete music;
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
