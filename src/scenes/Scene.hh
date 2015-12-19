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
	 * updates the scene, returning whatever scene should be the current scene next
	 * iteration of the main loop, most likely this one
	 */
	Scene * update(float deltaTime);


	/**
	 * This is where the scene's logic is implemented
	 */
	virtual Scene * logic(float deltaTime) = 0;


	/**
	 * Displays the scene on the screen
	 */
	virtual void render(SDL_Renderer * renderer) = 0;

private:

};


#endif
