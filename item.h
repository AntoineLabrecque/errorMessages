/* Antoine Labrecque */
#include "protectedChar.h"

class item {
private :
	protectedChar * message ;
	protectedChar * description ;

public :

	/* Algorithm: item ( error , solution )
	 * Pre:		error :: A protectedChar pointer to be put into the message member.
	 *			solution :: A protectedChar pointer to be put into the description member.
	 * Post:	An item is created and initialized.
	 * Return:	Nothing. */
	item ( protectedChar * & error , protectedChar * & solution ) ;
	
	/* Algorithm: getMessage ( )
	 * Pre:		Nothing.
	 * Post:	The message member is accessed.
	 * Return:	A copy of the message member, or NULL if it failed. */
	protectedChar * getMessage ( ) ;
	
	/* Algorithm: getDescription ( )
	 * Pre:		Nothing.
	 * Post:	The description member is accessed.
	 * Return:	A copy of the description member, or NULL if it failed. */
	protectedChar * getDescription ( ) ;
	
	/* Algorithm: ~item ( )
	 * Pre:		Nothing.
	 * Post:	The item is deallocated.
	 * Return:	Nothing. */
    ~item ( ) ;
} ;
/* Antoine Labrecque */
