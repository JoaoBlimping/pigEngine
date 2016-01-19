#ifndef REGION_H
#define REGION_H


/** region in a tilemap that can either teleport the player, or be where they get
 * teleported to */
typedef struct
{
	/** horizontal position of the region */
	int x;

	/** vertical position of the region */
	int y;

	/** width of the region */
	int width;

	/** height of the region */
	int height;

	/** the script that runs when the player enters the region. null for no script to be
	 * run */
	Script * script;
}
Region;

#endif
