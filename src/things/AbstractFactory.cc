#ifndef ABSTRACT_FACTORY_C
#define ABSTRACT_FACTORY_C


#include "AbstractFactory.hh"

#include <iostream>
#include <fstream>


#define NAME_BUFFER_LENGTH 32


template <typename T> void AbstractFactory<T>::registerFactory(ConcreteFactory<T> * factory)
{
	factories.push_back(factory);
}


template <typename T> T * AbstractFactory<T>::make(char const * filename)
{
	std::ifstream input(filename);
	char type[NAME_BUFFER_LENGTH];
	input.get(type,NAME_BUFFER_LENGTH);
}


#endif
