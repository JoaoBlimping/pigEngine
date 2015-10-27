//this scene shows the liquid pig studios logo and plays the sound


#ifndef SPLASH_SCENE_H
#define SPLASH_SCENE_H


#include "Scene.hh"

#include <SDL.h>

#include  "../mixer/mixer.hh"


class SplashScene:public Scene
{
public:
  //the filename of the jingle
  static char const * JINGLE_FILE;

  //the colours of the background
  static int const BACK_RED;
  static int const BACK_GREEN;
  static int const BACK_BLUE;
  static int const BACK_ALPHA;

  //loads it's own special assets
  SplashScene();

  //deletes it's assets
  ~SplashScene();

  //this is called every time there is an event that must be dealt with
  virtual void handleEvent(SDL_Event * event);

  //updates the scene
  //returns the new current scene
  virtual Scene * update(float deltaTime);

  //displays the scene
  virtual void render(SDL_Renderer * renderer);

private:
  //the sound that has to get played
  mixer_Sample * jingle;

  //the amount of time that has passed
  float elapsed;
};


#endif
