/* Antoine Labrecque */
class protectedChar {
private :
	char safe ;

public :

	/* Algroithm: protectedChar ( )
	 * Pre:		Nothing.
	 * Post:	A protected char is created and initialized to a newline.
	 * Return:	Nothing. */
	protectedChar ( ) ;
	
	/* Algorithm: setSafe ( one )
	 * Pre:		one :: A char.
	 * Post:	The safe member is set to one.
	 * Return:	Nothing. */
	void setSafe ( const char & one ) ;
	
	/* Algorithm: getSafe ( )
	 * Pre:		Nothing.
	 * Post:	The safe member of the protectedChar is accessed.
	 * Return:	A copy of the safe member. */
	char getSafe ( ) ;
	
	/* Algorithm: ~protectedChar ( )
	 * Pre:		Nothing.
	 * Post:	The protectedChar will be deallocated.
	 * Return:	Nothing. */
	~protectedChar ( ) ;
} ;
/* Antoine Labrecque */
