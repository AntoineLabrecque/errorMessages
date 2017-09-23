/* Antoine Labrecque */
#include <iostream>
#include "item.h"

using namespace std ;

/* Algorithm: item ( error , solution  )
 * Pre:		error :: A protectedChar pointer to be put into the message member.
 *			solution :: A protectedChar pointer to be put into the description member.
 * Post:	An item is created and initialized.
 * Return:	Nothing. */
item :: item ( protectedChar * & error , protectedChar * & solution )
{
	if ( error == NULL )
	{
		cout << "ERROR: item was given a NULL error!" << endl ;
	}
	if ( solution == NULL )
	{
		cout << "ERROR: item was given a NULL solution!" << endl ;
	}
	message = error ;
	description = solution ;
	return ;
}

/* Algorithm: getMessage ( )
 * Pre:		Nothing.
 * Post:	The message member is accessed.
 * Return:	A copy of the message member, or NULL if it failed. */
protectedChar * item :: getMessage ( )
{
	return message ;
}

/* Algorithm: getDescription ( )
 * Pre:		Nothing.
 * Post:	The description member is accessed.
 * Return:	A copy of the description member, or NULL if it failed. */
protectedChar * item :: getDescription ( ) 
{
	return description ;
}

/* Algorithm: ~item ( )
 * Pre:		Nothing.
 * Post:	The item is deallocated.
 * Return:	Nothing. */
item :: ~item ( )
{
	if ( message == NULL )
	{
		cout << "ERROR: ~item was given a NULL message!" << endl ;
	}
	else
	{
		delete [ ] message ;
		message = NULL ;
	}
	if ( description == NULL )
	{
		cout << "ERROR: ~item was given a NULL description!" << endl ;
	}
	else
	{
		delete [ ] description ;
		description = NULL ;
	}
	return ;
}
/* Antoine Labrecque */
