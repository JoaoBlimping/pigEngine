#include "GameState.hh"


GameState(int screenWidth,int screenHeight,Scene * currentScene):
screenWidth(screenWidth),
screenHeight(screenHeight),
currentScene(currentScene)
{}


~GameState()
{
	delete currentScene;
}


void setCurrentScene(Scene * newScene)
{
	delete currentScene;
	currentScene = newScene;
}


Scene * getCurrentScene()
{
	return currentScene;
}
