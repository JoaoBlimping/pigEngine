#ifndef PLAYABLE_CHARACTER_H
#define PLAYABLE_CHARACTER_H


#include "Character.hh"


/** the player's representation in the overworld */
class PlayableCharacter:public Character
{
public:
	/** sets all it's character stuff */
	PlayableCharacter();

	void render(SDL_Renderer * renderer,int cameraX,int cameraY,float deltaTime) = 0;

private:

};


/** concrete factory for creating overworld scenes */
class PlayableCharacterFactory:public ConcreteFactory<Character>
{
public:
	Character * operator()(StreamReader * data);
};


#endif
