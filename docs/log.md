# 27/10/2015
Ok this time the makefile is genuinely fixed, it has like directories in the bin folder
now, which makes no difference to me whatsoever.
Now it's time to get back to switching the thing managers over to a single manager class.

Just for a bit of fun there is now a circular dependancy because some of the things need
to make use of the asset manager, but the asset manager obviously uses them. I'll have to
make it that managers can be sent in to each other somehow.

Ok the managers work now I think. this is rather nice. I guess it's time to implement the
overworld. Actually first I need to redo the menu to use the keyboard/gamepad, so yeah I
need gamepad support and a decent GUI system.

# 26/10/2015
I reckon this assets system will be much better, but my makefile is still mucking up,
it's going to be much nicer when it actually works. Ok i'm pretty sure it works now.
Ok, I've made a mad new system where all of the managers are the same class which I should
have done in the beginning. oh yeah the makefile still doesn't totally work so have fun
with that future self. It kinda works but all the files in subdirectories are built from
source each time and never become bytecode.

# 25/10/2015
Working on the Level class which the OverworldScene class makes use of. Now i'm changing
the assets system so that I just have a global access point to all assets. It's probably
a little dodgy but I think it will also make things more simple and it worked well enough
for me in crazybone and the tap that leaked and leaked.

# 24/10/2015
Adding OverworldScene class which is where the overworld part of the game will
take place.
