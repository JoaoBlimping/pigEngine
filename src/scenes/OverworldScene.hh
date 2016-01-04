#ifndef OVERWORLD_SCENE_H
#define OVERWORLD_SCENE_H


#include "Scene.hh"
#include "../TileMap.hh"
#include "../things/StreamReader.hh"


/** The scene in which the overworld of the game takes place
 * You know it's like in a jrpg or whatever where everyone walks around from a top down
 * point of view and you talk to people and stuff */
class OverworldScene:public Scene
{
public:
	/**
	 * document when I actually figure out what it does
	 */
	OverworldScene();

	/**
	 * document when I figure out what it does
	 */
	~OverworldScene();

	void logic(float deltaTime);

	void renderContent(SDL_Renderer * renderer,float deltaTime);

private:
	/** The current level's map */
	TileMap * map;
};


/** concrete factory for creating overworld scenes */
class OverworldSceneFactory:public ConcreteFactory<Scene>
{
public:
	Scene * operator()(StreamReader * data);
};


#endif
