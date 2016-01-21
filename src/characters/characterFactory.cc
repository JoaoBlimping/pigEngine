#include "characterFactory.hh"

#include "NonPlayableCharacter.hh"
#include "PlayableCharacter.hh"


AbstractFactory<Character> characterFactory_factory;


void characterFactory_init()
{
	characterFactory_factory.registerFactory(new NonPlayableCharacterFactory(),"nonPlayable");
	characterFactory_factory.registerFactory(new PlayableCharacterSceneFactory(),"playable");
}
