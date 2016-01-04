#include "StaticScene.hh"

#include <SDL2/SDL.h>

#include "../assets.hh"
#include "../vm.hh"
#include "../backgrounds/Background.hh"
#include "../backgrounds/backgroundFactory.hh"
#include "../things/StreamReader.hh"


StaticScene::StaticScene(Background * background,int scriptIndex):
background(background),
scriptIndex(scriptIndex),
start(true)
{}


StaticScene::~StaticScene()
{}


void StaticScene::logic(float deltaTime)
{
	if (start)
	{
		start = false;
		vm_runScript(assets_scripts.getItem(scriptIndex));
	}
}


void StaticScene::renderContent(SDL_Renderer * renderer,float deltaTime)
{
	background->render(renderer,assets_getScreenWidth(),assets_getScreenHeight(),deltaTime);
}


Scene * StaticSceneFactory::operator()(StreamReader * data)
{
	Background * background = backgroundFactory_factory(data);
	int scriptIndex = data->readInt();
	return new StaticScene(background,scriptIndex);
}
