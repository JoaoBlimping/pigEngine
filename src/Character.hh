#ifndef CHARACTER_H
#define CHARACTER_H


/** a Character that the player can interact with in the overworld */
class Character
{
public:
	/** creates the character and sets it's stuff */
	Character(EventPage * pages,int nPages);

	/** deallocates the event pages */
	virtual ~Character();

	/** update the character */
	void update(float deltaTime);

	/** renders the character on Tha screeeeeeeen */
	virtual void render(int cameraX,int cameraY,SDL_Renderer * renderer,float deltaTime) = 0;

private:
	/** the character's horizontal tile position */
	int xPosition;

	/** the character's vertical tile position */
	int yPosition;
};


#endif
