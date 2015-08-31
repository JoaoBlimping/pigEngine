//this is like a scene that can be the current focus of the game


#ifndef SCENE_H
#define SCENE_H


#include "Graphics.h"


class Scene
{
public:
  //updates the scene
  //returns the new current scene
  virtual Scene update(float deltaTime) = 0;

  //displays the scene
  virtual void render(Graphics g) = 0;
};


#endif
