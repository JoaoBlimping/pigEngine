#include "Scene.hh"


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
		gui->update(deltaTime);
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
