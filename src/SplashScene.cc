#include "SplashScene.h"


SplashScene::SplashScene()
{
  elapsed = 0;
}


SplashScene::~SplashScene()
{

}


Scene * SplashScene::update(float deltaTime)
{
  elapsed += deltaTime;

  return this;
}


void SplashScene::render(SDL_Renderer * renderer)
{

}