#ifndef ABSTRACT_FACTORY_C
#define ABSTRACT_FACTORY_C


#include "AbstractFactory.hh"

#include <iostream>
#include <fstream>


#define NAME_BUFFER_LENGTH 32


template <typename T> void AbstractFactory<T>::registerFactory(ConcreteFactory<T> * factory,char const * name)
{
	factories[name] = factory;
}


template <typename T> T * AbstractFactory<T>::operator()(char const * filename)
{
	//get factory name
	std::ifstream input(filename);
	std::skipws(input);
	char type[NAME_BUFFER_LENGTH];
	input.get(type,NAME_BUFFER_LENGTH);

	std::cout << "ftype is " << type << std::endl;

	//get factory
	ConcreteFactory<T> * factory = factories.at(type);

	//make thing
	T * product = (*factory)(&input);

	//close input
	input.close();

	return product;
}


template <typename T> T * AbstractFactory<T>::operator()(std::istream * input)
{
	//get factory name
	char type[NAME_BUFFER_LENGTH];
	input->get(type,NAME_BUFFER_LENGTH);

	std::cout << "type is " << type << std::endl;

	//get factory
	ConcreteFactory<T> * factory = factories.at(type);

	//make thing
	T * product = (*factory)(input);

	return product;
}


#endif
