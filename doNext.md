# 10/12/2015
Make managers use C file io instead of c++, I'm pretty sure it'll make the compiled
program smaller and anyway I like it better.
For some reason it's saying that all the stuff I define in assets.hh is multiply defined,
I'll have to figure that out tomoroow. nah fixed it, they have to be extern for some
reason. Anyway, that's all the new errors ironed out. Next thing I have to do is get the
gui system working with the scripting system that I made.

# 9/12/2015
Ok zippitty zoopers today we have the problem of emscripten not seeming to know about the
mixer. This might be some kind of thing where I need to do more configuration on emcc, so
a google search is probably in order there.

# 8/12/2015
Move the item loading functors back to assets because they rely on assets and also they
are not necessarily essential to the original item's type and that.
 - maps will be loaded as needed.
 - tilesets are managed
 
Geany is still making backup files when I don't want it to, I'll have to fix that. Also
If I can get a terminal emulator that runs in this window that would be pretty cool cos
then I can run everything from inside this pretty much.
 

# 7/12/2015
god damn fix up the Manager.hh weirdness and then make tilemap work.

# 2/12/2015
Ok so now that the scripting language has been implemented, alhtough not integrated, it's
time to get back to the real engine. the first thing to do it make the overworld scene
appear, then we add characters, control them with a gamepad or keyboard, and also the
npc characters must be controlled also.
Then it's time to integrate the scripting language.
