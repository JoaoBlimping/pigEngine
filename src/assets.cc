#include "assets.hh"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "things/Image.hh"
#include "things/Animation.hh"
#include "things/Sound.hh"
#include "things/Font.hh"
#include "things/Skin.hh"

#include "pigScript/Script.hh"


#define IMAGES_DIR "assets/images/"
#define ANIMATIONS_DIR "assets/animations/"
#define SOUNDS_DIR "assets/sounds/"
#define FONTS_DIR "assets/fonts/"
#define SCRIPTS_DIR "assets/scripts/"


Image * ImageLoader::operator()(char const * filename,SDL_Renderer * renderer)
{
	Image * image = new Image();
	if (!image->loadFromFile(renderer,filename))
	{
		printf("error loading file %s\n",filename);
	}
	return image;
}

Animation * AnimationLoader::operator()(char const * filename,SDL_Renderer * renderer)
{
	//open the file
	std::ifstream animFile(filename);
	if (!animFile.is_open())
	{
		printf("can't open animation file %s\n",filename);
	}

	int imageIndex;
	int frames;
	float speed;

	animFile >> imageIndex;
	animFile >> frames;
	animFile >> speed;

	//close the file
	animFile.close();

	//run the function on the filename
	return new Animation(assets_images.getItem(imageIndex),frames,speed);
}

Sound * SoundLoader::operator()(char const * filename,SDL_Renderer * renderer)
{
	Sound * sound = Mix_LoadWAV(filename);
	if (sound == NULL)
	{
		printf("couldn't open soundfile %s\n",filename);
	}
	return sound;
}


Font * FontLoader::operator()(char const * filename,SDL_Renderer * renderer)
{
	//open the file
	std::ifstream fontFile(filename);
	if (!fontFile.is_open())
	{
		printf("can't open font file %s\n",filename);
	}

	int imageIndex;
	int characterWidth;
	int spacing;

	fontFile >> imageIndex;
	fontFile >> characterWidth;
	fontFile >> spacing;

	//close the file
	fontFile.close();

	return new Font(assets_images.getItem(imageIndex),characterWidth,spacing);
}


Script * ScriptLoader::operator()(char const * filename,SDL_Renderer * renderer)
{
	return new Script(filename);
}


Manager<Image,ImageLoader> assets_images(IMAGES_DIR);

Manager<Animation,AnimationLoader> assets_animations(ANIMATIONS_DIR);

Manager<Sound,SoundLoader> assets_sounds(SOUNDS_DIR);

Manager<Font,FontLoader> assets_fonts(FONTS_DIR);

Manager<Script,ScriptLoader> assets_scripts(SCRIPTS_DIR);

Skin * assets_windowSkin = NULL;

Skin * assets_selectSkin = NULL;

static int screenWidth = 0;

static int screenHeight = 0;


void assets_init(SDL_Renderer * renderer,SDL_Window * window)
{
	//initialise managers
	assets_images.init(renderer);
	assets_animations.init(renderer);
	assets_sounds.init(renderer);
	assets_fonts.init(renderer);
	assets_scripts.init(renderer);
	assets_windowSkin = new Skin(assets_images.getItem(6));//TODO: remove magic
	assets_selectSkin = new Skin(assets_images.getItem(8));//TODO: remove magic

	//set screen width and height
	SDL_GetWindowSize(window,&screenWidth,&screenHeight);
}


int assets_getScreenWidth()
{
	return screenWidth;
}


int assets_getScreenHeight()
{
	return screenHeight;
}
