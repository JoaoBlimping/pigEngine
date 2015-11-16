//reads a list and does something to each entry, storing the result

#ifndef MANAGER_H
#define MANAGER_H


#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include <SDL.h>

#include "Utils.hh"


#define LISTFILE "list"


using namespace std;


template <class T> class Manager
{
public:
  //create a manager with a function pointer to make items, and one to deallocate them
  Manager(char const * pDirectory,
          T * (*pCreate)(char const * filename,SDL_Renderer * renderer)):
  directory(pDirectory),
  create(pCreate)
  {};

  //uses the deallocation function on all of it's things
  ~Manager()
  {
    //free all of the images it contains
    for (typename vector<T *>::iterator it = items.begin();it != items.end();++it)
    {
      delete *it;
    }
  };

  //this is when all the stuff gets loaded
  void init(SDL_Renderer * renderer)
  {
    //create the listfile's name
    char * listFile = Utils::concatenate(directory,LISTFILE);

    //load the list of items
    ifstream list(listFile);

    //delete the listfile's name
    delete[] listFile;

    if (!list.is_open())
    {
      printf("can't open item list %s\n",listFile);
      return;
    }

    char * line;

    while (list >> line)
    {
      char * filename = Utils::concatenate(directory,line);

      //run the function on the file
      T * item = create(filename,renderer);
      printf("loaded %s\n",filename);

      items.push_back(item);

      //deallocate the filename's memory
      delete[] filename;
    }

    list.close();
  };

  //gives you an item that the manager holds
  T * getItem(int index)
  {
    return items[index];
  };

private:
  //list of items
  std::vector<T *> items;
  //the directory the items are stored in
  char const * directory;
  //function pointer to turn list item to real item
  T * (*create)(char const * filename,SDL_Renderer * renderer);
};


#endif
