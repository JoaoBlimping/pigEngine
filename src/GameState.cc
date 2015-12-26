#include "GameState.hh"


GameState::GameState(int screenWidth,int screenHeight,Scene * currentScene):
screenWidth(screenWidth),
screenHeight(screenHeight),
currentScene(currentScene)
{}


GameState::~GameState()
{
	delete currentScene;
}


void GameState::setCurrentScene(Scene * newScene) const
{
	delete currentScene;
	currentScene = newScene;
}


Scene * GameState::getCurrentScene() const
{
	return currentScene;
}
