#ifndef CONNECT_CONTROLLER_SCENE_H
#define CONNECT_CONTROLLER_SCENE_H


#include "Scene.hh"


/**
 * Scene in which the user connects however many controllers they desire
 */
class ConnectControllerScene:public Scene
{
public:
	void logic(float deltaTime);

	void render(SDL_Renderer * renderer);

private:
	/**
	 * the number of controllers that have been connected
	 */
	int connectedControllers;
};

#endif
