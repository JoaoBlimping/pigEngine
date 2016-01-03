#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H


#include <iostream>
#include <fstream>
#include <map>

#include <danylib/danylib.hh>


/** template class that creates a specific type of thing by taking in a stream containing
 * the data */
template <typename T> class ConcreteFactory
{
public:
	/** creates the thing */
	virtual T * operator()(std::istream * data) = 0;
};


/** template class for abstract factory that makes things of some subclass by taking
 * a bunch of data which starts with the subclass's registered name */
template <typename T> class AbstractFactory
{
public:
	/** add a new type of concrete factory that can be used to create thingoids */
	void registerFactory(ConcreteFactory<T> * factory,char * name);

	/** create a thing
	 * uses an istream to get the data to make the data reading nice and easy */
	T * operator()(char const * filename);

private:
	/** maps factories to the name that is given for them */
    std::map<char const *,ConcreteFactory<T> *,danylib_cmpstrptr> factories;
};


//include implementation because of templates
#include "AbstractFactory.cc"


#endif
