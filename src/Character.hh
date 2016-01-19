#ifndef CHARACTER_H
#define CHARACTER_H


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

	/** renders the character on Tha screeeeeeeen */
	virtual void render(SDL_Renderer * renderer,int cameraX,int cameraY,float deltaTime) = 0;

private:
	/** the character's horizontal tile position */
	int xPosition;

	/** the character's vertical tile position */
	int yPosition;
};


#endif
