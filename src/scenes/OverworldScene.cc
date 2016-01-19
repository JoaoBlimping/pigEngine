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
	//TODO: stuff
}


void OverworldScene::renderContent(SDL_Renderer * renderer,float deltaTime)
{
	//display the background
	background->render(renderer,assets_getScreenWidth(),assets_getScreenHeight(),deltaTime);

	//display the lower tiles
	map->render(renderer);

	//display the characters

	//display the upper tiles

	//display the overlay
	overlay->render(renderer,assets_getScreenWidth(),assets_getScreenHeight(),deltaTime);

}


Scene * OverworldSceneFactory::operator()(StreamReader * data)
{
	return new OverworldScene();
}
