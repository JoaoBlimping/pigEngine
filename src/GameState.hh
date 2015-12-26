#ifndef GAME_STATE_H
#define GAME_STATE_H


#include "scenes/Scene.hh"

//TODO: make a factory that creates this at the start of the game based on a file


/** class that contains the game's current state */
class GameState
{
public:
	/** creates the game state object
	 * currentScene will be the first scene of the game. */
	GameState(int screenWidth,int screenHeight,Scene * currentScene);

	/** deallocates the current scene */
	~GameState();

	/** sets the game's current scene and deletes the old one */
	void setCurrentScene(Scene * newScene) const;

	/** gives you the current scene of the game to deal with as you wish */
	Scene * getCurrentScene() const;

	/** an array of integers with arbitrary length that represent game variables */
	mutable int * globalVariables;

	/** the number of global variables */
	mutable int nGlobablVariables;

	/** an array of booleans of arbitrary length that represent game switches */
	mutable bool * globalSwitches;

	/** the number of global switches */
	mutable int nGlobalSwitches;

	/** the screen width of the game */
	int screenWidth;

	/** the screen height of the game */
	int screenHeight;

private:
	/** the current scene */
	mutable Scene * currentScene;
};


#endif
