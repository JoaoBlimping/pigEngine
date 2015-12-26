#ifndef VM_H
#define VM_H


#include "GameState.hh"
#include "pigScript/VirtualMachine.hh"
#include "pigScript/Script.hh"


/** initialise the vm, and give it stuff that it needs */
void vm_init(GameState const * gameState);


/** runs a script in a new thread, the ScriptReturn is set when the script finishes */
void vm_runScript(Script * script);


#endif
