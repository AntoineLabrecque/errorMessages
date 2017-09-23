/* Antoine Labrecque */
#include "Node.h"
#include <iostream>

using namespace std ;

/* Algoritm: Node ( info , post )
 * Pre:		info :: A pointer to an Element.
 *			post :: A pointer to the next Node, or NULL if none come after it as of yet.
 * Post:	A Node is created and initialized.
 * Return:	Nothing. */
Node :: Node ( Element * & info , Node * & post )
{
	if ( info == NULL )
	{
		cout << "ERROR: Node was given a NULL Element pointer!" << endl ;
		return ;
	}
	data = info ;
	next = post ;
	return ;
}

/* Algorithm: setNext ( post )
 * Pre:		post :: A Node pointer.
 * Post:	The next member is set to post.
 * Return:	True if successful, false if otherwise. */
void Node :: setNext ( Node * & post )
{
	next = post ;
	return ;
}

/* Algorithm: getData ( )
 * Pre:		Nothing.
 * Post:	The data member is accessed.
 * Return:	The Element in the Node. */
Element * Node :: getData ( )
{
	return data ;
}

/* Algorithm: getNext ( )
 * Pre:		Nothing.
 * Post:	The next member is accessed.
 * Return:	A pointer to the next Node.*/
Node * Node :: getNext ( )
{
	return next ;
}

/* Algorithm: ~Node ( )
 * Pre:		Nothing.
 * Post:	The Node is deallocated.
 * Return:	Nothing. */
Node :: ~Node ( )
{
	delete data ;
	data = NULL ;
	next = NULL ;
	return ;
}
/* Antoine Labrecque */
