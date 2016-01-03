#include "sceneFactory.hh"


AbstractFactory<Scene> sceneFactory_factory;


void sceneFactory_init()
{
	sceneFactory_factory.registerFactory();
}
