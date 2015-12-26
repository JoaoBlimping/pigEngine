#ifndef TILE_MAP_H
#define TILE_MAP_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "things/Tileset.hh"


/**
 * A map of tile ids that can display itself using some tileset and also gives collision
 * information about the tiles
 */
class TileMap
{
public:
  /**
   * creates a tilemap
   */
  TileMap();

  /**
   * deallocates the map's tile data but not the tileset
   */
   ~TileMap();

 /**
  * displays the tilemap
  * uses the camera position to display the tiles to the screen, however, if this would
  * cause it render stuff of the screen the camera is moved to avoid this if possible
  */
  void render(SDL_Renderer * renderer);

  /**
   * centres the camera on a specified position
   * sets the target centre position of the camera
   */
   void centre(int x,int y);

private:
  /**
   * the tileset used to draw the map and get it's collision information
   * displays the map's tiles and contains the information required to detect collisions
   * with the level. The TileMap does not take responsibility for deleting it
   */
  Tileset * tileset;
  
  /**
   * The tiles that make up the level
   */
  Tile * tiles;
};


#endif
