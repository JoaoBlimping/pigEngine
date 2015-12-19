#ifndef OVERWORLD_SCENE_H
#define OVERWORLD_SCENE_H


#include "Scene.hh"
#include "../TileMap.hh"


/**
 * The scene in which the overworld of the game takes place
 * You know it's like in a jrpg or whatever where everyone walks around from a top down
 * point of view and you talk to people and stuff
 */
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

	Scene * logic(float deltaTime);

	void render(SDL_Renderer * renderer);

private:
	/**
	 * The current level's map
	 */
	TileMap * map;

};


#endif
