#include "vm.hh"

#include <SDL2/SDL_thread.h>

#include "pigScript/VirtualMachine.hh"
#include "pigScript/Script.hh"


static VirtualMachine virtualMachine;




static int runScriptInThread(void * data)
{
	vm_Necessities * necessities = (vm_Necessities *)data;
	necessities->vm->execute(necessities->script);
	return 0;
}


void vm_runScript(Script * script)
{
	vm_Necessities necessities;
	necessities.vm = &virtualMachine;
	necessities.script = script;
	SDL_Thread * thread = SDL_CreateThread(runScriptInThread,"vm_thread",
											  (void*)(&necessities));
}
