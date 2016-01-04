#ifndef BACKGROUND_FACTORY_H
#define BACKGROUND_FACTORY_H


#include "../things/AbstractFactory.hh"
#include "Background.hh"


/** abstract factory that creates backgrounds */
extern AbstractFactory<Background> backgroundFactory_factory;


/** initialises the background factory */
void backgroundFactory_init();


#endif
