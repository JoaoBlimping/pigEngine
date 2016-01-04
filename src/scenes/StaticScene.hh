#ifndef STATIC_SCENE_H
#define STATIC_SCENE_H


#include "Scene.hh"

#include <SDL2/SDL.h>

#include "../backgrounds/Background.hh"
#include "../things/StreamReader.hh"


/** Scene that contains pretty much any scene that only contains gui type stuff or basic
 * graphics */
class StaticScene:public Scene
{
public:
	/** creates a static scene
	 * provides the StaticScene with the things it needs to live which are it's background
	 * and the script that it runs */
	StaticScene(Background * background,int scriptIndex);

	//deletes it's assets
	~StaticScene();

	void logic(float deltaTime);

	void renderContent(SDL_Renderer * renderer,float deltaTime);

private:
	/** true only on it's first run of logic */
	bool start;

	/** the background it displays */
	Background * background;

	/** the index of the script it is to run */
	int scriptIndex;
};


/** concrete factory that creates splash scenes, even though there isn't really anything
 * to do */
class StaticSceneFactory:public ConcreteFactory<Scene>
{
public:
	Scene * operator()(StreamReader * data);
};


#endif
