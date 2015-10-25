//manages fonts ay


#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H


class FontManager
{
public:
  //some useful constants for ye
  static char const * FONT_DIR;
  static char const * FONT_LIST;

  //destroys all of the fonts
  ~FontManager();

  //loads all the fonts
  void init();

  //gives you a font
  Font * getFont();

private:
  std::vector<Font *> fonts;
};


#endif
