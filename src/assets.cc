#include "assets.hh"

#include <SDL.h>
#include <SDL/SDL_mixer.h>

#include "things/Image.hh"
#include "things/Animation.hh"
#include "things/Sound.hh"
#include "things/Font.hh"


#define IMAGES_DIR "assets/images/"
#define ANIMATIONS_DIR "assets/animations/"
#define SOUNDS_DIR "assets/sounds/"

#define FONT_FILE "assets/font.pig"


//the manager loading functions
Image * loadImageFromFile(char const * filename,SDL_Renderer * renderer);
Animation * loadAnimationFromFile(char const * filename,SDL_Renderer * renderer);
Sound * loadSoundFromFile(char const * filename,SDL_Renderer * renderer);

//loading but not for a manager
Font * loadFontFromFile(char const * filename);


//create the manager objects
Manager<Image> assets_images("assets/images/",&loadImageFromFile);
Manager<Animation> assets_animations("assets/animations/",&loadAnimationFromFile);
Manager<Sound> assets_sounds("assets/sounds/",&loadSoundFromFile);

//create teh font object
Font * assets_font;


void assets_init(SDL_Renderer * renderer)
{
  //initialise managers
  assets_images.init(renderer);
  assets_animations.init(renderer);
  assets_sounds.init(renderer);

  //load the font
  assets_font = loadFontFromFile(FONT_FILE);
}


Image * loadImageFromFile(char const * filename,SDL_Renderer * renderer)
{
  Image * image = new Image();
  image->loadFromFile(renderer,filename);
  return image;
}


Animation * loadAnimationFromFile(char const * filename,SDL_Renderer * renderer)
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

  //get the images thingo


  //run the function on the filename
  return new Animation(assets_images.getItem(imageIndex),
                       frames,speed);
}


Sound * loadSoundFromFile(char const * filename,SDL_Renderer * renderer)
{
  Sound * sound = Mix_LoadWAV(filename);
  if (sound == NULL)
  {
    printf("couldn't open soundfile %s\n",filename);
  }
  return sound;
}


Font * loadFontFromFile(char const * filename)
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
