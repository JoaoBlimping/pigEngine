#ifndef MENU_SCENE_H
#define MENU_SCENE_H


#include "Scene.hh"

#include <SDL.h>

#include "../assets.hh"
#include "../things/Button.hh"


class MenuScene:public Scene
{
public:
  //creates the gui window
  MenuScene();

  //deletes it's assets
  ~MenuScene();

  void logic(float deltaTime);

  void render(SDL_Renderer * renderer);
};


#endif
