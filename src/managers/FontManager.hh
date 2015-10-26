//manages fonts ay


#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H


#include "../things/Font.hh"


class FontManager
{
public:
  //some useful constants for ye
  static char const * FONT_DIR;
  static char const * FONT_LIST;

  //destroys all of the fonts
  ~FontManager();

  //loads all the fonts
  void init(ImageManager const * const images);

  //gives you a font
  Font * getFont();

private:
  std::vector<Font *> fonts;
};


#endif
