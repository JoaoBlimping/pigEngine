#include "MenuScene.hh"

#include "../assets.hh"
#include "../things/Button.hh"


MenuScene::MenuScene()
{}


MenuScene::~MenuScene()
{}


void MenuScene::logic(float deltaTime)
{}


void MenuScene::renderContent(SDL_Renderer * renderer)
{}


Scene * MenuSceneFactory::operator()(std::istream * data)
{
	return new MenuScene();
}
