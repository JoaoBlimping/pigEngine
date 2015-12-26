#ifndef VM_H
#define VM_H


#include "pigScript/VirtualMachine.hh"
#include "pigScript/Script.hh"


typedef struct
{
	VirtualMachine * vm;
	Script * script;
}
vm_Necessities;


/** runs a script in a new thread, the ScriptReturn is set when the script finishes */
void vm_runScript(Script * script);


#endif
