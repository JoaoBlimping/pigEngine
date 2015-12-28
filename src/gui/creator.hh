#ifndef CREATOR_H
#define CREATOR_H


#include "Node.hh"


/** creates a text box made up of a window node containing a text node with the specified
 * text, and a clicker node which lets you end the window */
Node * creator_createTextBox(char const * content);


/** creates a box made up of a window node containing a top text, and then other texts
 * which are inside a selector, which lets you select an option and then activate it
 * to return it's number */
Node * creator_createMultipleChoice(char const * top, char const * * questions);



#endif
