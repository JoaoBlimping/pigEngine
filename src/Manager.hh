//reads a list and does something to each entry, storing the result

#ifndef MANAGER_H
#define MANAGER_H


#include <vector>

#include <SDL.h>


template <class T> class Manager
{
public:
  //create a manager with a function pointer to make items, and one to deallocate them
  Manager(char * directory,char * listFile,
          T * (*pCreate)(SDL_Renderer * renderer,ifstream * data));

  //uses the deallocation function on all of it's things
  ~Manager();

  //this is when all the stuff gets loaded
  void init(SDL_Renderer * renderer);

  //gives you an item that the manager holds
  T * getItem(int index);

private:
  //list of items
  std::vector<T *> items;
  //the directory the items are stored in
  char * directory;
  //the list file containing all the items names
  char * listFile;
  //function pointer to turn list item to real item
  T * (*create)(SDL_Renderer * renderer,ifstream * data);
};


#endif
