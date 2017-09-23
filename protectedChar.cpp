/* Antoine Labrecque */
#include "protectedChar.h"

/* Algroithm: protectedChar ( one )
 * Pre:		Nothing.
 * Post:	A protected char is created and initialized to a newline.
 * Return:	Nothing. */
protectedChar :: protectedChar ( )
{
	safe = '\n' ;
	return ;
}

/* Algorithm: setSafe ( one )
 * Pre:		one :: A char.
 * Post:	The safe member is set to one.
 * Return:	Nothing. */
void protectedChar :: setSafe ( const char & one )
{
	safe = one ;
	return ;
}

/* Algorithm: getSafe ( )
 * Pre:		Nothing.
 * Post:	The safe member of the protectedChar is accessed.
 * Return:	A copy of the safe member. */
char protectedChar :: getSafe ( )
{
	return safe ;
}

/* Algorithm: ~protectedChar ( )
 * Pre:		Nothing.
 * Post:	The protectedChar will be deallocated.
 * Return:	Nothing. */
protectedChar :: ~protectedChar ( )
{
	safe = '\n' ;
	return ;
}
/* Antoine Labrecque */
