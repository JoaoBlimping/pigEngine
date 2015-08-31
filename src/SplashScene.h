//this scene shows the liquid pig studios logo and plays the sound


#ifndef SPLASH_SCENE_H
#define SPLASH_SCENE_H


#include "Scene.h"

#include "Graphics.h"


class SplashScene:public Scene
{
public:
  //updates the scene
  //returns the new current scene
  virtual SplashScene update(float deltaTime) = 0;

  //displays the scene
  virtual void render(Graphics g) = 0;
};


#endif
