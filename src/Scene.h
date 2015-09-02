//this is like a scene that can be the current focus of the game


#ifndef SCENE_H
#define SCENE_H


#include <SDL.h>


class Scene
{
public:
  //updates the scene
  //returns the new current scene
  virtual Scene * update(float deltaTime) = 0;

  //displays the scene
  virtual void render(SDL_Renderer * renderer) = 0;
};


#endif
