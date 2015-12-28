#ifndef VM_H
#define VM_H


#include "GameState.hh"
#include "pigScript/VirtualMachine.hh"
#include "pigScript/Script.hh"


/** initialise the vm, and give it stuff that it needs */
void vm_init(GameState const * gameState);


/** runs a script in a new thread */
void vm_runScript(Script * script);


/** notify the running script of something, usually a gui return value */
void vm_notify(int value);


#endif
