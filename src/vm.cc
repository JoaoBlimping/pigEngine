#include "vm.hh"

#include <SDL2/SDL_thread.h>


#include "gui/creator.hh"

#include "pigScript/VirtualMachine.hh"
#include "pigScript/Script.hh"


static VirtualMachine virtualMachine;
static GameState const * game;
static int notification;

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
	//TODO: remove magic numbers and make this a fraction of the screen or something
	game->getCurrentScene()->addGuiNode(creator_createTextBox((char *)args),200,200);
	while (notification == 0);
}


static void ask(uint8_t * args,int * variables)
{
	bool finished;
	Node * textBox;
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


void vm_notify(int value)
{
	notification = value;
}


void vm_runScript(Script * script)
{
	notification = 0;
	Necessities necessities;
	necessities.vm = &virtualMachine;
	necessities.script = script;
	SDL_Thread * thread = SDL_CreateThread(runScriptInThread,"vm_thread",
											  (void*)(&necessities));
}
