#ifndef SCENE_FACTORY_H
#define SCENE_FACTORY_H


#include "../things/AbstractFactory.hh"
#include "Scene.hh"


/** abstract factory that creates scenes */
extern AbstractFactory<Scene> sceneFactory_factory;


/** initialises the scene factory */
void sceneFactory_init();


#endif
