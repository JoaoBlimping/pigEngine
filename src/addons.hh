#ifndef ADDONS_H
#define ADDONS_H


#include "GameState.hh"

#include "pigScript/VirtualMachine.hh"


/** adds all of this engine's addons to the given virtual machine */
void addons_addAddons(GameState * gameState,VirtualMachine * virtualMachine);


#endif
