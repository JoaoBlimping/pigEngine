//this scene shows the liquid pig studios logo and plays the sound


#ifndef SPLASH_SCENE_H
#define SPLASH_SCENE_H


#include "Scene.h"

#include <SDL.h>


class SplashScene:public Scene
{
public:
  //updates the scene
  //returns the new current scene
  virtual Scene * update(float deltaTime) = 0;

  //displays the scene
  virtual void render(SDL_Renderer * renderer) = 0;
};


#endif
