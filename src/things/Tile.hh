#ifndef TILE_H
#define TILE_H


/**
 * This is what a tile is stored as
 */
typedef uint16_t Tile;


/**
 * the directions in which overworld collisions can occur
 */
enum direction
{
	Up(1),
	Down,
	Left,
	Right
}


#endif
