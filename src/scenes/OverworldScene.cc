#include "OverworldScene.hh"


OverworldScene::OverworldScene(TileMap * map,Character * characters,int nCharacters,
							   Background * background,Background * overlay):
map(map),
characters(characters),
nCharacters(nCharacters),
background(background),
overlay(overlay)
{}


OverworldScene::~OverworldScene()
{
	delete map;
	delete[] characters;
	delete background;
	delete overlay;
}


void OverworldScene::logic(float deltaTime)
{
	//update characters
	for (int i = 0;i < nCharacters;i++) characters[i].update(deltaTime);

	//if the player has stepped into a region, see if it's important
	for (std::map<Region,char *,danylib_cmpstr>::iterator it = map->regions.begin();
		 it != map->regions.end();++it)
	{
		//the player is in the region
		if (*it.x <= player->xPosition && *it.x + *it.width >= player->xPosition &&
			*it.y <= player->yPosition && *it.y + *it.height >= player->yPosition)
		{
			//it's important
			if (*it.script != NULL) vm_runScript(*it.script);
		}
	}
}


void OverworldScene::renderContent(SDL_Renderer * renderer,float deltaTime)
{
	//display the background
	background->render(renderer,assets_getScreenWidth(),assets_getScreenHeight(),deltaTime);

	//display the lower tiles
	map->renderBack(renderer,cameraX,cameraY);

	//display the characters
	for (int i = 0;i < nCharacters;i++)
	{
		characters[i].render(renderer,cameraX,cameraY,deltaTime);
	}

	//display the upper tiles
	map->renderFront(renderer,cameraX,cameraY);

	//display the overlay
	overlay->render(renderer,assets_getScreenWidth(),assets_getScreenHeight(),deltaTime);
}


Scene * OverworldSceneFactory::operator()(StreamReader * data)
{
	return new OverworldScene();
}
