//this is like a scene that can be the current focus of the game


#ifndef SCENE_H
#define SCENE_H


#include <SDL.h>

#include "Assets.h"


class Scene
{
public:
  //virtual desctructor so that subclasses can delete their shit
  virtual ~Scene(){};

  //updates the scene
  //returns the new current scene
  virtual Scene * update(Assets const * const assets,float deltaTime) = 0;

  //displays the scene
  virtual void render(Assets const * const assets,SDL_Renderer * renderer) = 0;
};


#endif
