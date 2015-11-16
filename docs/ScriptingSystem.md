# Scripting System
Since the main part of this game is going to be like a JRPG style overworld, it is going
to need to be able to do basic stuff like have characters do stuff when interacted with
and cause events, and also this same system can be used to run the game's menus and stuff
since they will need a fairly solid system for following a set of instructions over time.

## Required abilities
The system will need to be able to do the following things:
 - Display a text box that closes when the user presses the main action button
 - change to a different scene
 - start a battle
 - wait for characters to follow a set of movements
 - delete characters
 - teleport charcaters
 - alter global variables and switches
 - conditional stuff based on global variables and switches as well as other stuff and
 local variables
 - multiple choice thingies

This can be acheived with threads, since every time something that blocks the script
occurs, it is in a called function which can simply wait until whatever it is has
completed.
