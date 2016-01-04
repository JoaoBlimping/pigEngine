#ifndef ABSTRACT_FACTORY_C
#define ABSTRACT_FACTORY_C


#include "AbstractFactory.hh"


template <typename T> void AbstractFactory<T>::registerFactory(ConcreteFactory<T> * factory,char const * name)
{
	factories[name] = factory;
}


template <typename T> T * AbstractFactory<T>::operator()(char const * filename)
{
	//get factory name
	StreamReader input(filename);
	char * type = input.readToken();

	//get factory
	ConcreteFactory<T> * factory = factories.at(type);

	//make thing
	T * product = (*factory)(&input);

	return product;
}


template <typename T> T * AbstractFactory<T>::operator()(StreamReader * input)
{
	//get factory name
	char * type = input->readToken();

	//get factory
	ConcreteFactory<T> * factory = factories.at(type);

	//make thing
	T * product = (*factory)(input);

	return product;
}


#endif
