#ifndef MENU_SCENE_H
#define MENU_SCENE_H


#include "Scene.hh"

#include <SDL.h>

#include "../assets.hh"
#include "../things/Button.hh"


class MenuScene:public Scene
{
public:
  //the position of the button
  static int const PLAY_BUTTON_X;
  static int const PLAY_BUTTON_Y;

  //creates the button
  MenuScene();

  //deletes it's assets
  ~MenuScene();

  //this is called every time there is an event that must be dealt with
  virtual void handleEvent(SDL_Event * event);

  //updates the scene
  //returns the new current scene
  virtual Scene * update(float deltaTime);

  //displays the scene
  virtual void render(SDL_Renderer * renderer);

private:

  //the button to start playing
  Button * playButton;
};


#endif
