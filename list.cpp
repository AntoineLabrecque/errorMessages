/* Antoine Labrecque */
#include "list.h"
#include <iostream>

using namespace std ;

/* Algorithm: list ( )
 * Pre:		Nothing.
 * Post:	A List is created.
 * Return:	Nothing. */
list :: list ( )
{
	length = 0 ;
	beginning = NULL ;
	return ;
}

/* Algorithm: insertHead ( datum )
 * Pre:		datum :: A pointer to an Element that will be inserted into the list.
 * Post:	A new Node is inserted at the head of the list with datum as its Element.
 * Return:	Nothing. */
void list :: insertHead ( Element * & datum )
{
	if ( datum == NULL )
	{
		cout << "ERROR: insertHead was given a pointer to a NULL Element!" << endl ;
		return ;
	}
	beginning = new Node ( datum , beginning ) ;
	length ++ ;
	return ;
}

/* Algorithm: getBeginning ( )
 * Pre:		Nothing.
 * Post:	The beginning member of the list is accessed.
 * Return:	A pointer to the first Node in the list. */
Node * list :: getBeginning ( )
{
	return beginning ;
}

/* Algorithm: getLength ( )
 * Pre:		Nothing.
 * Post:	The length member of the list is accessed.
 * Return:	The length of the list. */
int list :: getLength ( )
{
	return length ;
}

/* Algorithm: deleteNode ( target )
 * Pre:		target :: The Element that will have its occurrence in a Node removed from the list.
 * Post:	The first Node with a matching Element will be deleted.
 * Return:	True if successful, false if otherwise. */
bool list :: deleteNode ( Element * & target )
{
	if ( target == NULL )
	{
		cout << "ERROR: deleteNode was given a NULL target!" << endl ;
		return false ;
	}
	Node * runner = beginning , * walker = NULL ;
	while ( runner != NULL )
	{
		if ( target == runner -> getData ( ) )
		{
			if ( runner == beginning )
			{
				beginning = runner -> getNext ( ) ;
			}
			else
			{
				Node * temp = runner -> getNext ( ) ;
				walker -> setNext ( temp ) ;
			}
			length -- ;
			return true ;
		}
		walker = runner ;
		runner = runner -> getNext ( ) ;
	}
	return false ;
}

/* Algorithm: ~list ( )
 * Pre:		Nothing.
 * Post:	The list and all the memory on the heap that it had is deallocated.
 * Return:	Nothing. */
list :: ~list ( )
{
	Node * runner = beginning , * walker ;
	while ( runner != NULL )
	{
		walker = runner ;
		runner = runner -> getNext ( ) ;
		delete walker ;
	}
	length = 0 ;
	beginning = NULL ;
	return ;
}
/* Antoine Labrecque */
