#include "addons.hh"


GameState * game;


static void say(uint8_t * args,int * variables)
{
	//TODO: should create a new gui window in the current scene and only returns when it
	//TODO: has been closed
}



void addons_addAddons(GameState * gameState,VirtualMachine * virtualMachine)
{
	game = gameState;
	
	virtualMachine->registerAddon(say,"say");
}
