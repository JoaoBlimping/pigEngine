#include "Manager.hh"

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <SDL.h>

#include "Utils.hh"


using namespace std;


template <class T> Manager<T>::Manager(char * pDirectory,char * pListFile,
                                       T * (*pCreate)(SDL_Renderer * renderer,ifstream * data)):
directory(pDirectory),
listFile(pListFile),
create(pCreate)
{}


template <class T> Manager<T>::~Manager()
{
  //free all of the images it contains
  for (typename vector<T *>::iterator it = items.begin();it != items.end();++it)
  {
    delete *it;
  }
}


template <class T> void Manager<T>::init(SDL_Renderer * renderer)
{
  //load the list of items
  ifstream list(listFile);

  if (!list.is_open())
  {
    printf("can't open item list %s\n",listFile);
    return;
  }

  char * line;

  while (list >> line)
  {
    char * filename = Utils::concatenate(directory,line);

    //open the file
    ifstream data(filename);

    if (!data.is_open())
    {
      printf("can't open data file %s\n",filename);
    }

    //run the function on the file
    T * item = create(renderer,data);
    printf("loaded %s\n",filename);
    data.close();

    items.push_back(item);

    //deallocate the filename's memory
    delete[] filename;
  }

  list.close();
}


template <class T> T *  Manager<T>::getItem(int index)
{
  return items[index];
}
