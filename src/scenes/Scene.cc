#include "Scene.hh"

#include "../Controller.hh"
#include "../input.hh"


Scene::Scene()
{
	gui = NULL;
}

Scene::~Scene()
{
	//does nothing since the gui should already be deleted
}

void Scene::update(float deltaTime)
{
	//if there is a gui node to deal with
	if (gui != NULL)
	{
		int guiReturn = gui->update(deltaTime);
		if (guiReturn != 0)
		{
			printf("kill it\n");
			//TODO: do something with this value
			removeGuiNode();
		}
	}

	//if not
	else
	{
		logic(deltaTime);
	}
}

void Scene::render(SDL_Renderer * renderer)
{
	renderContent(renderer);
	if (gui != NULL) gui->render(renderer,guiX,guiY);

	ControllerState const * state = input_getControllerState(0);
	SDL_SetRenderDrawColor(renderer,0xFF,0x00,0x00,0xFF);
	SDL_Rect drawRect = {0,0,32,32};

	//give us button debug stuff
	for (int i = 0;i < NButtons;i++)
	{
		//if it's pressed
		if (state->buttons[i])
		{
			SDL_RenderFillRect(renderer,&drawRect);
		}

		//if it's not
		else
		{
			SDL_RenderDrawRect(renderer,&drawRect);
		}
		drawRect.y += 32;
	}
}

void Scene::addGuiNode(Node * node,int x,int y)
{
	if (gui != NULL) delete gui;
	gui = node;
	guiX = x;
	guiY = y;
}

void Scene::removeGuiNode()
{
	if (gui != NULL)
	{
		delete gui;
		gui = NULL;
	}
}
