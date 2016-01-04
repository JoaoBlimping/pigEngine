#include "sceneFactory.hh"

#include "StaticScene.hh"
#include "OverworldScene.hh"


AbstractFactory<Scene> sceneFactory_factory;


void sceneFactory_init()
{
	sceneFactory_factory.registerFactory(new StaticSceneFactory(),"static");
	sceneFactory_factory.registerFactory(new OverworldSceneFactory(),"overworld");
}
