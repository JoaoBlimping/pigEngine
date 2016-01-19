#ifndef OVERWORLD_SCENE_H
#define OVERWORLD_SCENE_H


#include "Scene.hh"
#include "../TileMap.hh"
#include "../things/StreamReader.hh"
#include "backgrounds/Background.hh"


/** The scene in which the overworld of the game takes place
 * You know it's like in a jrpg or whatever where everyone walks around from a top down
 * point of view and you talk to people and stuff */
class OverworldScene:public Scene
{
public:
	/** hack.org.au
	 * sets all of the scene's things. oh yeah it takes ownership of everything*/
	OverworldScene(TileMap * map,Character * characters,int nCharacters,
				   Background * background,Background * overlay);

	/**
	 * document when I figure out what it does
	 */
	~OverworldScene();

	void logic(float deltaTime);

	void renderContent(SDL_Renderer * renderer,float deltaTime);

private:
	/** The current level's map */
	TileMap * map;

	/** the characters in the level */
	Character * characters;

	/** the number of characters */
	int nCharacters;

	/** the background of the scene */
	Background * background;

	/** the overlay of the scene */
	Background * overlay;
};


/** concrete factory for creating overworld scenes */
class OverworldSceneFactory:public ConcreteFactory<Scene>
{
public:
	Scene * operator()(StreamReader * data);
};


#endif
