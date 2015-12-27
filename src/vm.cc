#include "vm.hh"

#include <SDL2/SDL_thread.h>


#include "gui/creator.hh"

#include "pigScript/VirtualMachine.hh"
#include "pigScript/Script.hh"


static VirtualMachine virtualMachine;
static GameState const * game;

typedef struct
{
	VirtualMachine * vm;
	Script * script;
}
Necessities;


static void wait(uint8_t * args,int * variables)
{
	SDL_Delay(variables[args[0]]);
}


static void say(uint8_t * args,int * variables)
{
	game->getCurrentScene()->addGuiNode(creator_createTextBox("hello mates e bola ui have that diseasese tango stanky ass danky"));
}



static int runScriptInThread(void * data)
{
	Necessities * necessities = (Necessities *)data;
	necessities->vm->execute(necessities->script);
	return 0;
}


void vm_init(GameState const * gameState)
{
	game = gameState;
	virtualMachine.registerAddon(wait,"wait");
	virtualMachine.registerAddon(say,"say");
}


void vm_runScript(Script * script)
{
	Necessities necessities;
	necessities.vm = &virtualMachine;
	necessities.script = script;
	SDL_Thread * thread = SDL_CreateThread(runScriptInThread,"vm_thread",
											  (void*)(&necessities));
}
