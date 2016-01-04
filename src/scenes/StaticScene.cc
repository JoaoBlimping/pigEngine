#include "StaticScene.hh"

#include <SDL2/SDL.h>

#include "../assets.hh"
#include "../vm.hh"
#include "../backgrounds/Background.hh"
#include "../backgrounds/backgroundFactory.hh"


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


void StaticScene::renderContent(SDL_Renderer * renderer)
{
	background->render(renderer,100,100);//TODO: get proper numbers here
}


Scene * StaticSceneFactory::operator()(std::istream * data)
{
	Background * background = backgroundFactory_factory(data);
	int scriptIndex;
	data->operator>>(scriptIndex);

	return new StaticScene(background,scriptIndex);
}
