//this is like a scene that can be the current focus of the game


#ifndef SCENE_H
#define SCENE_H


#include <SDL.h>

#include "../assets.hh"


class Scene
{
public:
  //virtual desctructor so that subclasses can delete their shit
  virtual ~Scene(){};

  //this is called every time there is an event that must be dealt with
  virtual void handleEvent(SDL_Event * event) = 0;

  //updates the scene
  //returns the new current scene
  virtual Scene * update(float deltaTime) = 0;

  //displays the scene
  virtual void render(SDL_Renderer * renderer) = 0;
};


#endif
