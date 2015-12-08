//the game's overworld


#ifndef OVERWORLD_SCENE_H
#define OVERWORLD_SCENE_H


#include "Scene.h"


class OverworldScene:public Scene
{
public:
  //creates the scene with all the stuff it needs
  OverworldScene();

  //destroys the overworld scene, but not it's level data
  ~OverworldScene();

  //this is called every time there is an event that must be dealt with
  virtual void handleEvent(SDL_Event * event);

  //updates the scene
  //returns the new current scene
  virtual Scene * update(float deltaTime);

  //displays the scene
  virtual void render(SDL_Renderer * renderer);

private:

};


#endif
