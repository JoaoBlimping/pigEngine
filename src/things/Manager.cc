#include "Manager.cc"


Manager::Manager(char const * pDirectory):
directory(pDirectory)
{}


Manager::~Manager()
{
  //free all of the images it contains
  for (vector<T *>::iterator it = items.begin();it != items.end();++it)
  {
    delete *it;
  }
};


void Manager::init(SDL_Renderer * renderer)
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
    T * item = loader(filename,renderer);
    printf("loaded %s\n",filename);

    items.push_back(item);

    //deallocate the filename's memory
    delete[] filename;
  }

  list.close();
};


T * getItem(int index)
{
  return items[index];
};
