#ifndef SPLASH_SCENE_H
#define SPLASH_SCENE_H


#include "Scene.hh"

#include <SDL.h>


//TODO: a lot of stuff

/** scene that displays my logo and stuff */
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

  //updates the scene
  //returns the new current scene
  void logic(float deltaTime);

  //displays the scene
  void renderContent(SDL_Renderer * renderer);

private:
  //the sound that has to get played
  //mixer_Sample * jingle;

  //the amount of time that has passed
  float elapsed;
};


#endif
