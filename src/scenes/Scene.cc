#include "Scene.hh"


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
	if (gui != NULL) gui->render(renderer);
}

void Scene::addGuiNode(Node * node)
{
	if (gui != NULL) delete gui;
	gui = node;
}

void Scene::removeGuiNode()
{
	if (gui != NULL)
	{
		delete gui;
		gui = NULL;
	}
}
