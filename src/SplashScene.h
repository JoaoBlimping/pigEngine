//this scene shows the liquid pig studios logo and plays the sound


#ifndef SPLASH_SCENE_H
#define SPLASH_SCENE_H


#include "Scene.h"

#include <SDL.h>


class SplashScene:public Scene
{
public:
  //loads it's own special assets
  SplashScene();

  //deletes it's assets
  ~SplashScene();

  //updates the scene
  //returns the new current scene
  virtual Scene * update(float deltaTime);

  //displays the scene
  virtual void render(SDL_Renderer * renderer);

private:
  float elapsed;
};


#endif
