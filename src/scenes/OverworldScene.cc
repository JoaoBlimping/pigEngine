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


void OverworldScene::renderContent(SDL_Renderer * renderer)
{

}


Scene * OverworldSceneFactory::operator()(std::istream * data)
{
	return new OverworldScene();
}
