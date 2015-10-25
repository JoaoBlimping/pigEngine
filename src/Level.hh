//contains level data and stuff


#ifndef LEVEL_H
#define LEVEL_H


#include <SDL.h>


class Level
{
public:
  Level(char * pTiles,bool * pCollisions,int pWidth,int pHeight,Image * pTileset);

  //gives you a specific tile of the level
  char getTile(int x,int y,int z);

  //renders the level to the screen
  void render(int cameraX,int cameraY,int screenWidth,int screenHeight,
              SDL_Renderer * renderer);

private:
  //the three levels of visual tile data
  char * tiles;

  //the collision map
  bool * collisions;

  //dimensions of the level
  int width;
  int height;

  //the level's tileset image
  Image * tileset;
};
