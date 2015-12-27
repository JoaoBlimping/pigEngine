#ifndef SCENE_H
#define SCENE_H


#include <SDL2/SDL.h>

#include "../assets.hh"
#include "../gui/Node.hh"


/** The game will have a focus on a certain set of functionality at all times, and these
 * different kinds of functionality are contained in different kinds of scenes, the
 * interface of these are contained by this superclass */
class Scene
{
public:
	/** creates a scene, mostly just so it can set gui to NULL */
	Scene();

	/** does nothing since the gui should already be deleted */
	virtual ~Scene();

	/**updates the scene, returning whatever scene should be the current scene next
	 * iteration of the main loop, most likely this one */
	void update(float deltaTime);

	/** displays the scene along with any gui elements currently active */
	void render(SDL_Renderer * renderer);


	/** This is where the scene's logic is implemented */
	virtual void logic(float deltaTime) = 0;


	/** Displays the scene's content on the screen */
	virtual void renderContent(SDL_Renderer * renderer) = 0;

	/** adds a gui node to the scene so that it focuses on that until it is done */
	void addGuiNode(Node * node,int x = 0,int y = 0);

	/** removes and deallocates the current gui node if there is one */
	void removeGuiNode();

private:
	/** the scene's root gui node */
	Node * gui;

	/** the horizontal position to show the gui node at */
	int guiX;

	/** the vertical position to show the gui node at */
	int guiY;
};


#endif
