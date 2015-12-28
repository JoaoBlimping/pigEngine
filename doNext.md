# 27/12/2015
Ok, so I need to make windows and stuff look nice which will require two things, I will
need to make it that they are placed in correct positions and sizes on the screen, and
then also I need to make window skins, they will not need to be a type of asset, and
can simply be images which may or may not be wrapped in another class, but there will
need to be a data file telling the game what the window skin images are.

apparantly I need to redo adding controllers to the game to make it work as a desktop
program.

# 26/12/2015
looks like it won't work as html5. so it's just a desktop app now!! need to make it that
it runs at a regular framerate, then I guess it's back to business.
Everything is going bloody swimmingly. next thing to do is actually make the gui system
work so that I can test it with the script system.

# 25/12/2015
lol, it's christmas.
Yeah but anyway i'm still going to make it that the Makefile copies in the the files
from some nice directory, then it builds, then they are removed again. NICE!
awwwwwwwwwwwwwww yeah It's working pretty DAMN(tm) nicely.

# 21/12/2015
I need to make danylib and pigscript build to emscripten's bytecode, but at the moment
they seem to be unable to even detect header files. perhaps I need to make them be js
files or something like that. or perhaps bc file.
This is hella annyoing, anyway the worst case is just that I have to copy and paste these
files into pig Engine, actually a good idea would be to temporarily copy them in using
the make file or something. yeah i'll copy in the .bc files or something and the header
files since i need those I guess. I can put them in their own special directories that
say that they are what they are yea heayh.

# 20/12/2015
so the scene needs to be accessable to the addon functions since they do stuff to it, but
I can't just make it available everywhere. maybe you initialize the addon file, providing
a pointer to a pointer to the scene, so that when it changes they will still have it.
also make it that logic no longer returns the next scene, it will be done exclusively by
scripts that change it for the base scene class.

ok one better is I will create a game state object which belongs to main, but is also
given to the addon file when it is initialised!!!!!!!!

# 19/12/2015
make the basic scene class contain the functionality to contain GUI windows. To run the
scripts there will have to be a central virtual machine since it'll contain all the addon
functions and that. the only problem there is they will need access to the current scene,
so perhaps I can put the virtual machine and the current scene in some header file with a
bunch of game constants like the screen height and stuff.
OR I can just provide a pointer to a pointer to the current scene and make sure they
don't try any funny business. yeah so then the addons just get the current scene and do
whatever they desired with it, and then when they are done they return so that the script
may carry on. they can block for ages though if they want I guess.

# 18/12/2015
Next thing I must do is make it that you can set the controls for controllers since they
seem to do weird shit by default.
OKKKK SO WHat needs to jhapend is for the menu scene to use the new gui stuff so I can see
if it worksssssssssss yeaewa. other than that yeee it all seems pretty goodd ayyyy.

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
