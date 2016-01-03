#ifndef MENU_SCENE_H
#define MENU_SCENE_H


#include "Scene.hh"

#include <SDL2/SDL.h>

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

  void renderContent(SDL_Renderer * renderer);
};


/** concrete factory for creating menu scenes */
class MenuSceneFactory:public ConcreteFactory<Scene>
{
public:
	Scene * operator()(std::istream * data);
};


#endif
