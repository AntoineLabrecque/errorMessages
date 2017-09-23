/* Antoine Labrecque */
#include "Node.h"

class list {
private :
	int length ;
	Node * beginning ;

public :

	/* Algorithm: list ( )
	 * Pre:		Nothing.
	 * Post:	A List is created.
	 * Return:	Nothing. */
	list ( ) ;
	
	/* Algorithm: insertHead ( datum )
	 * Pre:		datum :: An Element that will be inserted into the list.
	 * Post:	A new Node is inserted at the head of the list with datum as its Element.
	 * Return:	Nothing. */
	void insertHead ( Element * & datum ) ;
	
	/* Algorithm: getBeginning ( )
	 * Pre:		Nothing.
	 * Post:	The beginning member of the list is accessed.
	 * Return:	A pointer to the first Node in the list. */
	Node * getBeginning ( ) ;
	
	/* Algorithm: getLength ( )
	 * Pre:		Nothing.
	 * Post:	The length member of the list is accessed.
	 * Return:	The length of the list. */
	int getLength ( ) ;
	
	/* Algorithm: deleteNode ( target )
	 * Pre:		target :: The Element that will have its occurrence in a Node removed from the list.
	 * Post:	The first Node with a matching Element will be deleted.
	 * Return:	True if successful, false if otherwise. */
	bool deleteNode ( Element * & target ) ;
	
	/* Algorithm: ~list ( )
	 * Pre:		Nothing.
	 * Post:	The list and all the memory on the heap that it had is deallocated.
	 * Return:	Nothing. */
	~list ( ) ;
} ;
/* Antoine Labrecque */
