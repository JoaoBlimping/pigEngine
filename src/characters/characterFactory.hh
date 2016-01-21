#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H


#include "../things/AbstractFactory.hh"
#include "Character.hh"


/** abstract factory that creates scenes */
extern AbstractFactory<Character> characterFactory_factory;


/** initialises the scene factory */
void characterFactory_init();


#endif
