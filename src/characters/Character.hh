#ifndef CHARACTER_H
#define CHARACTER_H


#include "../things/AbstractFactory.hh"


/** defines the directions in which a character can move
 * used to create arrays of directions to define movement patterns for non playable
 * characters */
enum moveDirection
{
	Up = 0,
	Down,
	Left,
	Right,
	TowardPlayer,
	AwayFromPlayer,
	Random,
	None
};


/** a Character that the player can interact with in the overworld */
class Character
{
public:
	/** creates the character and sets it's position and that */
	Character(int xPosition,int yPosition);

	/** deallocates the event pages */
	virtual ~Character();

	/** update the character */
	void update(float deltaTime);

	/** the internal logic for the character to do :DDDDDDDDDDDD */
	virtual void logic(float deltaTime);

	/** renders the character on Tha screeeeeeeen */
	virtual void render(SDL_Renderer * renderer,int cameraX,int cameraY,float deltaTime) = 0;

	/** tells you where the character plans to move next */
	moveDirection getNextMove();

	/** tells the character where it is to move next */
	void setNextMove(moveDirection nextMove);

private:
	/** the character's horizontal tile position */
	int xPosition;

	/** the character's vertical tile position */
	int yPosition;

	/** how far though moving the character is */
	float moveState;

	/** how many seconds it takes the character to move one space */
	float moveSpeed;

	/** the direction in which the character must move next */
	moveDirection nextMove;
};


#endif
