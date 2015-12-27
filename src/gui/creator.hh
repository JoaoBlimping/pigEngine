#ifndef CREATOR_H
#define CREATOR_H


#include "Node.hh"


/** creates a text box made up of a window node containing a text node with the specified
 * text, and a clicker node which lets you end the window */
Node * creator_createTextBox(char const * content);



#endif
