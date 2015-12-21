#include "Scene.hh"


~Scene()
{
	//does nothing since the gui should already be deleted
}

void update(float deltaTime)
{
	//if there is a gui node to deal with
	if (gui != NULL)
	{
		gui->update(deltaTime);
	}

	//if not
	else
	{
		update(deltaTime);
	}
}

void render(SDL_Renderer * renderer)
{
	renderContent(renderer);
	if (gui != NULL) gui->render(renderer);
}

void addGuiNode(Node * node)
{
	if (gui != NULL) delete gui;
	gui = node;
}

void removeGuiNode()
{
	if (gui != NULL)
	{
		delete gui;
		gui = NULL;
	}
}
