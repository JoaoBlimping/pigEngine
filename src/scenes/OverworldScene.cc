#include "OverworldScene.hh"


OverworldScene::OverworldScene()
{

}


OverworldScene::~OverworldScene()
{

}


void OverworldScene::logic(float deltaTime)
{
	//TODO: stuff
}


void OverworldScene::renderContent(SDL_Renderer * renderer,float deltaTime)
{

}


Scene * OverworldSceneFactory::operator()(StreamReader * data)
{
	return new OverworldScene();
}
