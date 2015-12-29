#include "vm.hh"

#include <SDL2/SDL_thread.h>

#include <danylib/danylib.hh>

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
	//don't get a previous return value
	notification = 0;

	//TODO: remove magic numbers and make this a fraction of the screen or something
	game->getCurrentScene()->addGuiNode(creator_createTextBox((char *)args),200,200);

	//wait until the user has clicked to move on to the next part of the script
	while (!notification);
}


static void ask(uint8_t * args,int * variables)
{
	//don't get a previous return value
	notification = 0;

	uint8_t returnVariable = args[0];
	char * question = (char *)(args + 1);
	char const * answers = danylib_findNextString(question);
	game->getCurrentScene()->addGuiNode(creator_createMultipleChoice(question,answers),200,200);

	//wait for a selection to be made
	while (!notification);
	variables[returnVariable] = notification;
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
	virtualMachine.registerAddon(ask,"ask");
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
