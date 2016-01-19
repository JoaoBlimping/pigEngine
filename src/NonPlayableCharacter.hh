#ifndef NON_PLAYABLE_CHARACTER_H
#define NON_PLAYABLE_CHARACTER_H


#include "Character.hh"


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


/** describes the structure of an event page that the character can be using */
typedef struct
{
	/** the first variable it uses to test whether it should activate */
	int varA;

	/** the second variable it uses to test whether it should activate */
	int varB;

	/** says that this event page is good to go if varirables[varA] < variables[varB] */
	bool less;

	/** says that this event page is good to go if varirables[varA] == variables[varB] */
	bool equal;

	/** says that this event page is good to go if varirables[varA] > variables[varB] */
	bool greater;

	/** true iff the character can be walked over while on this event page */
	bool passable;

	/** true iff the script simply runs as soon as possible */
	bool automatic;

	/** the character's spritesheet while on this event page */
	Image * spritesheet;

	/** list of movements that the character must carry out while on this page */
	moveDirection * moveList;

	/** number of movements in this move list */
	int nMoves;

	/** the move that the move list is up to */
	int currentMove;

	/** the script that this event page runs */
	Script * script;
}
EventPage;


/** character which is not the player */
class NonPlayableCharacter:public Character
{
public:
	/** creates the character
	 * gives it it's stuff which it takes responsibility for */
	NonPlayableCharacter(EventPage * pages,int nPages);

	/** sets the character's event page to the current one it should be */
	void recheckEvents();

private:
	/** the character's event pages
	 * the pages that define the character's functionality for any given time. the
	 * character is responsible for deallocating them. */
	EventPage * pages;

	/** the number of event pages */
	int nPages;

	/** the currently active event page */
	int currentPage;

	/** if this is false, don't do anything */
	bool alive;
};


#endif
