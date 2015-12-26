#ifndef MANAGER_C
#define MANAGER_C

#include "Manager.hh"

#include <vector>
#include <iostream>
#include <fstream>


#define LINE_BUFFER_SIZE 100


template <class T,class L> Manager<T,L>::Manager(char const * pDirectory):
directory(pDirectory)
{}


template <class T,class L> Manager<T,L>::~Manager()
{
  //free all of the images it contains
  for (typename std::vector<T *>::iterator it = items.begin();it != items.end();++it)
  {
    delete *it;
  }
};


template <class T,class L> void Manager<T,L>::init(SDL_Renderer * renderer)
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

  char line[LINE_BUFFER_SIZE];

  while (list >> line)
  {
    char * filename = Utils::concatenate(directory,line);

    //run the function on the file
    T * item = loader(filename,renderer);
    printf("loaded %s\n",filename);

    items.push_back(item);

    //deallocate the filename's memory
    delete[] filename;
  }

  list.close();
};


template <class T,class L> T * Manager<T,L>::getItem(int index)
{
  return items[index];
};

#endif
