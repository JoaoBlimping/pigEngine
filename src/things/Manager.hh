//reads a list and does something to each entry, storing the result

#ifndef MANAGER_H
#define MANAGER_H


#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include <SDL.h>

#include "../Utils.hh"


#define LISTFILE "list"


using namespace std;


/**
 * Manages assets of a specific veriatey
 * Keeps a bunch of assets of one type in a list which is accessed by their id number
 * which has to be known beforehand.
 * Type T is the type of items that are managed and L is the type of the loader functor.
 */
template <typename T,class L> class Manager
{
public:
	/**
	 * Creates a manager.
	 * Creates the manager, setting it's working directory, the functor it uses to load
	 * items, and the functor it uses to delete them again. Doesn't initialise it.
	 */
	Manager(char const * pDirectory);

	/**
	 * deletes all of the items loaded by the manager
	 */
	~Manager()//TODO: what the fuck is going in here?

	/**
	 * Initialises the manager
	 * sets the manager up and also loads all of the items from the filesystem that it will
	 * be managing
	 */
	void init(SDL_Renderer * renderer);

	/**
	 * returns the item at the given index
	 */
	T * getItem(int index);

private:
	/**
	 * stores all of the items the manager has loaded
	 */
	std::vector<T *> items;

	/**
	 * the directory that the loader is run in.
	 * This is the directory where the list file is searched for and that all of the files
	 * are loaded relative to.
	 */
	char const * directory;

	/**
	 * function called to load each file
	 * any filename found in the list file then has this functor called on it.
	 */
	L loader;
};


#endif
