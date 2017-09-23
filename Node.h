/* Antoine Labrecque */
#include "Element.h"

class Node {
private :
	Element * data ;
	Node * next ;

public :

	/* Algoritm: Node ( info , post )
	 * Pre:		info :: An Element.
	 *			post :: A pointer to the next Node, or NULL if none come after it as of yet.
	 * Post:	A Node is created and initialized.
	 * Return:	Nothing. */
	Node ( Element * & info , Node * & post ) ;
	
	/* Algorithm: setNext ( post )
	 * Pre:		post :: A Node pointer.
	 * Post:	The next member is set to post.
	 * Return:	Nothing. */
	void setNext ( Node * & post ) ;
	
	/* Algorithm: getData ( )
	 * Pre:		Nothing.
	 * Post:	The data member is accessed.
	 * Return:	The Element in the Node. */
	Element * getData ( ) ;
	
	/* Algorithm: getNext ( )
	 * Pre:		Nothing.
	 * Post:	The next member is accessed.
	 * Return:	A pointer to the next Node.*/
	Node * getNext ( ) ;
	
	/* Algorithm: ~Node ( )
	 * Pre:		Nothing.
	 * Post:	The Node is deallocated.
	 * Return:	Nothing. */
	~Node ( ) ;
} ;
/* Antoine Labrecque */
