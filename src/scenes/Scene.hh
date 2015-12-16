#ifndef SCENE_H
#define SCENE_H


#include <SDL.h>

#include "../assets.hh"


/**
 * The game will have a focus on a certain set of functionality at all times, and these
 * different kinds of functionality are contained in different kinds of scenes, the
 * interface of these are contained by this superclass
 */
class Scene
{
public:
	/**
	 * Virtual destructor so that subclasses can deallocate their shit
	 */
	virtual ~Scene(){};

	/**
	 * Called by the main loop when there is an event that the scene should handle
	 */
	virtual void handleEvent(SDL_Event * event) = 0;

	/**
	 * updates the scene, returning whatever scene should be the current scene next
	 * iteration of the main loop, most likely this one
	 */
	virtual Scene * update(float deltaTime) = 0;

	/**
	 * Displays the scene on the screen
	 */
	virtual void render(SDL_Renderer * renderer) = 0;
};


#endif
