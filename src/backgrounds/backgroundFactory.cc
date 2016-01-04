#include "backgroundFactory.hh"

#include "Background.hh"
#include "ColouredBackground.hh"
#include "TileBackground.hh"


AbstractFactory<Background> backgroundFactory_factory;


void backgroundFactory_init()
{
	backgroundFactory_factory.registerFactory(new ColouredBackgroundFactory(),"coloured");
	backgroundFactory_factory.registerFactory(new TileBackgroundSceneFactory(),"tile");
}
