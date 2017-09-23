/* Antoine Labrecque */
#include <iostream>
#include <fstream>
#include <cstring>
#include "list.h"
using namespace std ;

const int maximumCharArraySize = 999 ;

const char * numbers = "0123456789" ;

/* Algorithm: quoteBypasser ( quote , offset )
 * Pre:		quote :: A pointer to a protectedChar array with a propper quote in it.
 *			offset :: The offset of one past the open-quote, must be at a part of the array where quotes are allowed and lower than the maximumCharArraySize.
 * Post:	offset is increased until it is at the end-quote.
 * Return:	True if successful, false if otherwise.*/
bool quoteBypasser ( protectedChar * & quote , int & offset )
{
	if ( quote == NULL )
	{
		cout << "ERROR: quoteBypasser was given a NULL quote!" << endl ;
		return false ;
	}
	if ( offset < 7 )
	{
		cout << "ERROR: quoteBypasser was given a offset where quotes are not allowed!" << endl ;
		return false ;
	}
	if ( offset >= maximumCharArraySize )
	{
		cout << "ERROR: quoteBypasser was given an offset that is too large!" << endl ;
		return false ;
	}
	if ( quote [ offset - 1 ] . getSafe ( ) != '\'' )
	{
		cout << "ERROR: quoteBypasser was given an offset that doesn't match an open-quote!" << endl ;
		return false ;
	}
	while ( quote [ offset ] . getSafe ( ) != '\'' )
	{
		if ( quote [ offset ++ ] . getSafe ( ) == '\0' )
		{
			cout << "ERROR: quoteBypasser reached the end of the array!" << endl ;
			return false ;
		}
	}
	return true ;
}

/* Algoritm: printProtectedChars ( letters )
 * Pre:		letters :: A protectedChar pointer.
 * Post:	The characters are read out to the console.
 * Return:	True if successful, false if otherwise. */
bool printProtectedChars ( protectedChar * & letters )
{
	if ( letters == NULL )
	{
		cout << "ERROR: printProtectedChar was given NULL data!" << endl ;
		return false ;
	}
	for ( int i = 0 ; letters [ i ] . getSafe ( ) != '\0' && i < maximumCharArraySize ; i ++ )
	{
		cout << letters [ i ] . getSafe ( ) ;
	}
	cout << endl ;
	return true ;
}

/* Algorithm: akaBypasser ( aka , start )
 * Pre:		aka :: A pointer to a protedtedChar array with a propper aka in it.
 *			start :: The offset of the space before the aka, must be where aka's are allowed and lower than the maximumCharArraySize.
 * Post:	start is increased until it is at the close paren.
 * Return:	True if successful, false if otherwise. */
bool akaBypasser ( protectedChar * & aka , int & start )
{
	if ( aka == NULL )
	{
		cout << "ERROR: akaBypasser was given a NULL aka!" << endl ;
		return false ;
	}
	if ( start < 9 )
	{
		cout << "ERROR: akaBypasser was given a start where aka's are not allowed!" << endl ;
		return false ;
	}
	if ( start >= maximumCharArraySize )
	{
		cout << "ERROR: akaBypasser was given a start that is too large!" << endl ;
		return false ;
	}
	if ( aka [ start ] . getSafe ( ) != ' ' || aka [ ++ start ] . getSafe ( ) != '(' )
	{
		cout << "ERROR: akaBypasser was given a start that doesn't match an aka!" << endl ;
		return false ;
	}
	if ( aka [ ++ start ] . getSafe ( ) == 'a' && aka [ ++ start ] . getSafe ( ) == 'k' && aka [ ++ start ] . getSafe ( ) == 'a' && aka [ ++ start ] . getSafe ( ) == ' ' && aka [ ++ start ] . getSafe ( ) == '\'' )
	{
		if ( ! quoteBypasser ( aka , ++ start ) )
		{
			cout << "ERROR: quoteBypasser returned false in akaBypasser!" << endl ;
			return false ;
		}
		if ( aka [ ++ start ] . getSafe ( ) == ')' )
		{
			return true ;
		}
	}
	cout << "ERROR: The end of the aka is formatted incorrectly in akaBypasser!" << endl ;
	return false ;
}

/* Algorithm: dataContained ( first , second )
 * Pre:		first :: A char pointer terminated by '\0'.
 *			second :: A protectedChar pointer terminated by '\0'.
 * Post:	first and second are compared.
 * Return:	True if first is in second, false otherwise. */
bool dataContained ( char * & first , protectedChar * & second )
{
	if ( first == NULL )
	{
		cout << "ERROR: dataEquivalence was given a NULL first!" << endl ;
		return false ;
	}
	if ( first [ 0 ] == '\0' )
	{
		return false ;
	}
	if ( second [ 0 ] . getSafe ( ) == '\0' )
	{
		cout << "ERROR: dataContained was given an empty second!" << endl ;
		return false ;
	}
	if ( second == NULL )
	{
		cout << "ERROR: dataEquivalence was given a NULL second!" << endl ;
		return false ;
	}
	bool insideQuote , directlyAfterQuote = false ;
	for ( int firstCounter = 0 , secondCounter = 0 , holder = 1 , arbitrary = -1 , conditionallyArbitrary = -1 ; secondCounter != maximumCharArraySize ; )
	{
		//cout << "line 36" << endl ;//test code
		insideQuote = false ;
		while ( first [ firstCounter ++ ] == second [ secondCounter ++ ] . getSafe ( ) && secondCounter != maximumCharArraySize )
		{
			//cout << "line 39" << endl ;//test code
			if ( first [ firstCounter ] == '\0' )
			{
				return true ;
			}
			if ( second [ secondCounter ] . getSafe ( ) == '\0' )
			{
				return false ;
			}
			if ( second [ secondCounter ] . getSafe ( ) == '\'' && ! directlyAfterQuote )
			{
				insideQuote = true ;
			}
			else if ( insideQuote )
			{
				if ( ! quoteBypasser ( second , secondCounter ) )
				{
					cout << "ERROR: quoteBypasser returned false in dataContained!" << endl ;
					return false ;
				}
				insideQuote = false ;
				directlyAfterQuote = true ;
			}
			else if ( directlyAfterQuote )
			{
				if ( second [ secondCounter ] . getSafe ( ) == ' ' && second [ secondCounter + 1 ] . getSafe ( ) == '(' )
				{
					if ( ! akaBypasser ( second , secondCounter ) )
					{
						cout << "ERROR: akaBypasser returned false in dataContained!" << endl ;
						return false ;
					}
					if ( second [ secondCounter ] . getSafe ( ) == ')' )
					{
						secondCounter ++ ;
					}
					else
					{
						cout << "ERROR: the end of an aka in second is formatted incorrectly in dataContained." << endl ;
					}
				}
				directlyAfterQuote = false ;
			}
			else if ( second [ secondCounter ] . getSafe ( ) == 'A' )
			{
				if ( second [ ++ secondCounter ] . getSafe ( ) != 'r' || second [ ++ secondCounter ] . getSafe ( ) != 'b' || second [ ++ secondCounter ] . getSafe ( ) != 'i' || second [ ++ secondCounter ] . getSafe ( ) != 't' || second [ ++ secondCounter ] . getSafe ( ) != 'r' || second [ ++ secondCounter ] . getSafe ( ) != 'a' || second [ ++ secondCounter ] . getSafe ( ) != 'r' || second [ ++ secondCounter ] . getSafe ( ) != 'y' || second [ ++ secondCounter ] . getSafe ( ) != ' ' || second [ ++ secondCounter ] . getSafe ( ) != 'n' || second [ ++ secondCounter ] . getSafe ( ) != 'u' || second [ ++ secondCounter ] . getSafe ( ) != 'm' || second [ ++ secondCounter ] . getSafe ( ) != 'b' || second [ ++ secondCounter ] . getSafe ( ) != 'e' || second [ ++ secondCounter ] . getSafe ( ) != 'r' || second [ ++ secondCounter ] . getSafe ( ) != ' ' )
				{
					cout << "ERROR: An arbitrary number is not formatted correctly in dataContained!" << endl ;//Todo: double check this and fix the space number search problem.
					
					return false ;
				}
				if ( second [ ++ secondCounter ] . getSafe ( ) == 'n' )
				{
					if ( arbitrary == -1 )
					{
						for ( int j = 0 ; j < 10 ; j ++ )
						{
							if ( first [ firstCounter ] == numbers [ j ] )
							{
								arbitrary = j ;
								firstCounter ++ ;
								break ;
							}
						}
						if ( arbitrary < 0 || arbitrary > 9 )
						{
							cout << "ERROR: arbitrary was not set properly in dataContained!" << endl ;
							return false ;
						}
						for ( int i = 1 ; arbitrary / i > 0 ; i *= 10 )
						{
							if ( arbitrary < i || arbitrary > 9 * i )
							{
								cout << "ERROR: arbitrary was not updated properly in dataContained!" << endl ;
								return false ;
							}
							for ( int j = 0 ; j < 10 ; j ++ )
							{
								if ( first [ firstCounter ] == numbers [ j ] )
								{
									firstCounter ++ ;
									arbitrary = arbitrary * 10 + j ;
									break ;
								}
							}
						}
					}
					else
					{
						do
						{
							firstCounter ++ ;
						} while ( first [ firstCounter ] == '0' || first [ firstCounter ] == '1' || first [ firstCounter ] == '2' || first [ firstCounter ] == '3' || first [ firstCounter ] == '4' || first [ firstCounter ] == '5' || first [ firstCounter ] == '6' || first [ firstCounter ] == '7' || first [ firstCounter ] == '8' || first [ firstCounter ] == '9' ) ;
					}
				}
				else if ( second [ secondCounter ] . getSafe ( ) == '>' && second [ ++ secondCounter ] . getSafe ( ) == ' ' && second [ ++ secondCounter ] . getSafe ( ) == 'n' )
				{
					if ( arbitrary < 0 )
					{
						cout << "ERROR: arbitrary was not set in dataContained!" << endl ;
						return false ;
					}
					if ( conditionallyArbitrary == -1 )
					{
						for ( int j = 0 ; j < 10 ; j ++ )
						{
							if ( first [ firstCounter ] == numbers [ j ] )
							{
								conditionallyArbitrary = j ;
								firstCounter ++ ;
								break ;
							}
						}
						if ( conditionallyArbitrary < 0 || conditionallyArbitrary > 9 )
						{
							cout << "ERROR: conditionallyArbitrary was not set properly in dataContained!" << endl ;
							return false ;
						}
						for ( int i = 1 ; arbitrary / i > 0 ; i *= 10 )
						{
							if ( conditionallyArbitrary < i || conditionallyArbitrary > 9 * i )
							{
								cout << "ERROR: conditionallyArbitrary was not updated properly in dataContained!" << endl ;
								return false ;
							}
							for ( int j = 0 ; j < 10 ; j ++ )
							{
								if ( first [ firstCounter ] == numbers [ j ] )
								{
									firstCounter ++ ;
									conditionallyArbitrary = conditionallyArbitrary * 10 + j ;
									break ;
								}
							}
						}
						if ( conditionallyArbitrary <= arbitrary )
						{
							return false ;
						}
                    }
                    else
					{
                        do
						{
							firstCounter ++ ;
						} while ( first [ firstCounter ] == '0' || first [ firstCounter ] == '1' || first [ firstCounter ] == '2' || first [ firstCounter ] == '3' || first [ firstCounter ] == '4' || first [ firstCounter ] == '5' || first [ firstCounter ] == '6' || first [ firstCounter ] == '7' || first [ firstCounter ] == '8' || first [ firstCounter ] == '9' ) ;
					}
				}
				else
				{
					cout << "ERROR: An arbitrary number is not formatted correctly in dataContained!" << endl ;
					return false ;
				}
				secondCounter ++ ;
			}
		}
		if ( secondCounter == maximumCharArraySize )
		{
			break ;
		}
		directlyAfterQuote = false ;
		if ( second [ holder ] . getSafe ( ) == '\'' )
		{
			secondCounter = holder + 1 ;
			if ( ! quoteBypasser ( second , secondCounter ) )
			{
				cout << "ERROR: quoteBypasser returned false in dataContained!" << endl ;
				return false ;
			}
			holder = ++ secondCounter ;
			firstCounter = 1 ;
		}
		else
		{
			firstCounter = 1 ;
			secondCounter = holder ;
			for ( insideQuote = false ; first [ 0 ] != second [ secondCounter ] . getSafe ( ) && secondCounter != maximumCharArraySize ; secondCounter ++ )
			{
				//cout << "line 52" << endl ;//test code
				if ( second [ secondCounter ] . getSafe ( ) == '\0' )
				{
					return false ;
				}
				if ( second [ secondCounter ] . getSafe ( ) == '\'' && ! directlyAfterQuote )
				{
					if ( ! quoteBypasser ( second , ++ secondCounter ) )
					{
						cout << "ERROR: quoteBypasser returned false in dataContained!" << endl ;
						//printProtectedChars ( second ) ;//test code
						return false ;
					}
					directlyAfterQuote = true ;
				}
				else if ( directlyAfterQuote )
				{
					if ( second [ secondCounter ] . getSafe ( ) == ' ' && second [ secondCounter + 1 ] . getSafe ( ) == '(' )
					{
						if ( ! akaBypasser ( second , secondCounter ) )
						{
							cout << "ERROR: akaBypasser returned false in dataContained!" << endl ;
							return false ;
						}
						if ( second [ secondCounter ] . getSafe ( ) != ')' )
						{
							cout << "ERROR: the end of an aka in second is formatted incorrectly in dataContained." << endl ;
							return false ;
						}
					}
					directlyAfterQuote = false ;
				}
                else if ( second [ secondCounter ] . getSafe ( ) == 'A' )
                {
                    if ( second [ ++ secondCounter ] . getSafe ( ) != 'r' || second [ ++ secondCounter ] . getSafe ( ) != 'b' || second [ ++ secondCounter ] . getSafe ( ) != 'i' || second [ ++ secondCounter ] . getSafe ( ) != 't' || second [ ++ secondCounter ] . getSafe ( ) != 'r' || second [ ++ secondCounter ] . getSafe ( ) != 'a' || second [ ++ secondCounter ] . getSafe ( ) != 'r' || second [ ++ secondCounter ] . getSafe ( ) != 'y' || second [ ++ secondCounter ] . getSafe ( ) != ' ' || second [ ++ secondCounter ] . getSafe ( ) != 'n' || second [ ++ secondCounter ] . getSafe ( ) != 'u' || second [ ++ secondCounter ] . getSafe ( ) != 'm' || second [ ++ secondCounter ] . getSafe ( ) != 'b' || second [ ++ secondCounter ] . getSafe ( ) != 'e' || second [ ++ secondCounter ] . getSafe ( ) != 'r' || second [ ++ secondCounter ] . getSafe ( ) != ' ' )
                    {
                        cout << "ERROR: An arbitrary number is not formatted correctly in dataContained!" << endl ;
                        return false ;
                    }
                    if ( second [ ++ secondCounter ] . getSafe ( ) == 'n' )
                    {
                    	if ( first [ 0 ] == '0' || first [ 0 ] == '1' || first [ 0 ] == '2' || first [ 0 ] == '3' || first [ 0 ] == '4' || first [ 0 ] == '5' || first [ 0 ] == '6' || first [ 0 ] == '7' || first [ 0 ] == '8' || first [ 0 ] == '9' )
                    	{
                    		if ( arbitrary == -1 )
                    		{
                        		for ( int j = 0 ; j < 10 ; j ++ )
                        		{
                        		    if ( first [ 0 ] == numbers [ j ] )
                        		    {
                        		        arbitrary = j ;
                        		        break ;
                        		    }
                        		}
                        		if ( arbitrary < 0 || arbitrary > 9 )
                        		{
                        		    cout << "ERROR: arbitrary was not set properly in dataContained!" << endl ;
                        		    return false ;
                        		}
                        		for ( int i = 1 ; arbitrary / i > 0 ; i *= 10 )
                        		{
                        		    if ( arbitrary < i || arbitrary > 9 * i )
                        		    {
                        		        cout << "ERROR: arbitrary was not updated properly in dataContained!" << endl ;
                        		        return false ;
                        		    }
                        		    for ( int j = 0 ; j < 10 ; j ++ )
                        		    {
                        		        if ( first [ firstCounter ] == numbers [ j ] )
                        		        {
                        		            firstCounter ++ ;
                        		            arbitrary = arbitrary * 10 + j ;
                        		            break ;
                        		        }
                        		    }
                        		}
                        	}
                        	break ;
                        }
                    }
                    else if ( second [ secondCounter ] . getSafe ( ) == '>' )
                    {
                    	if ( second [ ++ secondCounter ] . getSafe ( ) != ' ' || second [ ++ secondCounter ] . getSafe ( ) != 'n' )
                    	{
                    		cout << "ERROR: The end of Arbitrary number > n is formatted incorrectly!" << endl ;
                    		return false ;
                    	}
                    }
                    else
                    {
                        cout << "ERROR: second is not formatted correctly in dataContained!" << endl ;
                        return false ;
                    }
                }
			}
			if ( second [ secondCounter ++ ] . getSafe ( ) == '\0' )
			{
				return false ;
			}
			if ( first [ firstCounter ] == '\0' )
			{
				return true ;
			}
			if ( directlyAfterQuote )// Todo: fix the searching for quotes problem!!!
			{
				if ( second [ secondCounter ] . getSafe ( ) == ' ' && second [ secondCounter + 1 ] . getSafe ( ) == '(' )
				{
					if ( ! akaBypasser ( second , secondCounter ) )
					{
						cout << "ERROR: akaBypasser returned false in dataContained!" << endl ;
						return false ;
					}
					secondCounter ++ ;
				}
				holder = secondCounter ;
				directlyAfterQuote = false ;
			}
			else if ( second [ secondCounter ] . getSafe ( ) == '\'' )
			{
				if ( first [ firstCounter ++ ] == '\'' )
				{
					if ( first [ firstCounter ] == '\0' )
					{
						return true ;
					}
					if ( ! quoteBypasser ( second , ++ secondCounter ) )
					{
						cout << "ERROR: quoteBypasser returned false in dataContained!" << endl ;
						return false ;
					}
					if ( second [ ++ secondCounter ] . getSafe ( ) == '\0' )
					{
						return false ;
					}
				}
				else
				{
					return false ;
				}
				if ( second [ secondCounter ] . getSafe ( ) == ' ' && second [ secondCounter + 1 ] . getSafe ( ) == '(' )
				{
					if ( ! akaBypasser ( second , secondCounter ) )
					{
						cout << "ERROR: akaBypasser returned false in dataContained!" << endl ;
						return false ;
					}
					secondCounter ++ ;
				}
				holder = secondCounter ;
			}
			else
			{
				holder = secondCounter + 1 ;
			}
		}
	}
	cout << "ERROR: Infinite loop in dataContained!" << endl ;
	return false ;
}

/* Algorithm: printElement ( solo )
 * Pre:		solo :: An Element.
 * Post:	The character fields are read to standard output.
 * Return:	True if successful, false if otherwise. */
bool printElement ( Element & solo )
{
	bool success = true;
	protectedChar * holder = solo . getMessage ( ) ;
	if ( ! printProtectedChars ( holder ) )
	{
		cout << "ERROR: printProtectedChars returned false in printElement the first time!" << endl ;
		success = false ;
	}
	holder = solo . getDescription ( ) ;
	if ( ! printProtectedChars ( holder ) )
	{
		cout << "ERROR: printProtectedChars returned false in printElement the second time!" << endl ;
		return false ;
	}
	return success ;
}

/* Algorithm: listSearch ( key , map )
 * Pre:		key ::	A character array with the data to search for.
 *			map ::	A singly linked list that will have its elements searched.
 * Post:	A list is made that point to elements that have the data the key has.
 * Return:	A pointer to a list with the items that had the data from the key in them, or NULL if it failed. */
list * listSearch ( char * & key , list & map )
{
	if ( key == NULL )
	{
		cout << "ERROR: listSearch was given a NULL key!" << endl ;
		return NULL ;
	}
	list * hits = new list ;
	if ( hits == NULL )
	{
		cout << "ERROR: The heap is full in listSearch!" << endl ;
		return NULL ;	
	}
	Node * walker = map . getBeginning ( ) ;
	Element * elementHolderPtr = NULL ;
	for ( protectedChar * holder = NULL ; walker != NULL ; walker = walker -> getNext ( ) )
	{
        holder = walker -> getData ( ) -> getMessage ( ) ;
        if ( holder == NULL )
        {
        	cout << "ERROR: getMessage returned NULL in listSearch!" << endl ;
        }
        else
        {
        	//cout << "line 125" << endl ;//test code
        	if ( dataContained ( key , holder ) )
			{
				elementHolderPtr = walker -> getData ( ) ;
				if ( elementHolderPtr == NULL )
				{
					cout << "ERROR: getData returned NULL in listSearch!" << endl ;
				}
				else
				{
					hits -> insertHead ( elementHolderPtr ) ;
        	    	//cout << "line 136" << endl ;//test code
        	    }
        	}
		}
	}
	return hits ;
}
//reimplement this function!!!!
/* Algorithm: createArray ( copy )
 * Pre:     copy :: A singly linked list that will have an array made from its elements.
 * Post:    An item array is made alphadetically by message field.
 * Return:  A pointer to the array, or NULL if it failed.
item * createArray ( const list & copy )
{
    if ( copy . beginning == NULL )
    {
        cout << "ERROR: In createArray, copy . beginning is NULL!" << endl ;
        return NULL ;
    }
    item * * alphabetical = new item * [ copy . length ] , * iterator = copy . beginning , * holder = copy . beginning ;
    if ( alphabetical == NULL )
    {
    	cout << "ERROR: In createArray, alphabetical is NULL!" << endl ;
    	return NULL ;
    }
    int comparedAlphabetically ;
    for ( int i = 0 ; i < copy . length ; i ++ )
    {
        alphabetical [ i ] = iterator ;
        for ( int j = i ; j > 0 ; j -- )
        {
        	comparedAlphabetically = strcmp ( alphabetical [ j - 1 ] -> message , alphabetical [ j ] -> message ) ;
        	if ( comparedAlphabetically > 0 )
        	{
        		 holder = alphabetical [ j - 1 ] ;
        		 alphabetical [ j - 1 ] = alphabetical [ j ] ;
        		 alphabetical [ j ] = holder ;
        	}
        	else if ( comparedAlphabetically < 0 )
        	{
        		break ;
        	}
        	else
        	{
        		cout << "ERROR: In createArray, there are two identical errors are in the data!" << endl ;
        		delete [ ] alphabetical ;
        		return NULL ;
        	}
        	
        }
        iterator = iterator -> next ;
    }
    return alphabetical ;
}

/* Algorithm: initializeElementFromFile ( input )
 * Pre:		input :: The input filestream, each line must have less than 996 characters in it.
 * Post:	An item element is initialized.
 * Return:	A pointer to the initialized Element, or NULL if it failed. */
Element * initializeElementFromFile ( ifstream & input )
{
	char * holder = new char [ maximumCharArraySize ] ;
	if ( holder == NULL )
	{
		cout << "ERROR: The heap is too full for the character array in initializeElementFromFile!" << endl ;
		return NULL ;
	}
	input . getline ( holder , maximumCharArraySize ) ;
	int length = strlen ( holder ) + 1 ;
	protectedChar * message = new protectedChar [ length ] , * description  = NULL ;
	if ( message == NULL )
	{
		cout << "ERROR: The heap is too full for the first protectedCharacter array in initializeElementFromFile!" << endl ;
		delete [ ] holder ;
		return NULL ;
	}
	for ( int i = 0 ; i < length ; i ++ )
	{
		message [ i ] . setSafe ( holder [ i ] ) ;
	}
	input . getline ( holder , maximumCharArraySize ) ;
	length = strlen ( holder ) + 1 ;
	description = new protectedChar [ length ] ;
	if ( description == NULL )
	{
		cout << "ERROR: The heap is too full for the second protectedCharacter array in initializeElementFromFile!" << endl ;
		delete [ ] message ;
		delete [ ] holder ;
		return NULL ;
	}
	for ( int i = 0 ; i < length ; i ++ )
	{
		description [ i ] . setSafe ( holder [ i ] ) ;
	}
	Element * one = new Element ( message , description ) ;
	if ( one == NULL )
	{
		cout << "ERROR: The heap is too full for the Element in initializeElementFromFile!" << endl ;
		delete [ ] message ;
		delete [ ] description ;
	}
	delete [ ] holder ;
	return one ;
}

/* Algorithm: initializeListFromFile ( input )
 * Pre:		input :: A singly linked list, whose members are length and beginning.
 * Post:	The list is created and initialized by calling functions list, Element, and initializeElementFromFile, the entire filestream is read in and closed. 
 * Return:	True if successful, false if otherwise. */
bool initializeListFromFile ( ifstream & input , list & fill )
{
	if ( ! input . is_open ( ) )
	{
		cout << "ERROR: In initializeListFromFile, input is not open!" << endl ;
		return false ;
	}
	for ( Element * holder = NULL ; ! input . eof ( ) ; )
	{
		//cout << "line 196" << endl ;//test code
		holder = initializeElementFromFile ( input ) ;
		if ( holder == NULL )
		{
			cout << "ERROR: initializeElementFromFile returned NULL in initializeListFromFile!" << endl ;
		}
		else
		{
			//cout << "line 204" << endl ;//test code
			fill . insertHead ( holder ) ;
		}
    }
	input . close ( ) ;
	if ( input . is_open ( ) )
	{
		cout << "ERROR: In initializeListFromFile, file is open!" << endl ;
		return false ;
	}
	return true ;
}

/* Algorithm: printList ( tally )
 * Pre:		tally :: A list.
 * Post:	The character fields are read out to the standard output.
 * Return:	True if successful, false if otherwise. */
bool printList ( list & tally )
{
	bool success = true ;
	for ( Node * walker = tally . getBeginning ( ) ; walker != NULL ; walker = walker -> getNext ( ) )
	{
		cout << endl ;
		if ( walker -> getData ( ) == NULL )
		{
			cout << "ERROR: getData returned NULL in printList!" << endl ;
			success = false ;
		}
		else if ( ! printElement ( * walker -> getData ( ) ) )
		{
			cout << "ERROR: printElement returned false in printList!" << endl ;
			success = false ;
		}
	}
	return success ;
}


/* Algorithm 1: main
 * Pre:		A text file in the current working directory named errorMessagesJournal. It's format must be:[error message][newline][message discription][newline], repeatidly.
 * Post:	The error message journal is accessable in a user-friendly way.
 * Return:	0. */
int main ( )
{
	ifstream errorMessagesJournal ;
	errorMessagesJournal . open ( "errorMessagesJournal.txt" , ios :: in ) ;
	if ( ! errorMessagesJournal . is_open ( ) )
	{
		cout << "ERROR: In main, errorMessageJournal is not open!" << endl ;
		return 0 ;
	}
	list group , * results = NULL ;
	//cout << "line 281" << endl ;//test code
	if ( ! initializeListFromFile ( errorMessagesJournal , group ) )
	{
		cout << "ERROR: in main, initializeListFromFile returned false!" << endl ;
		return 0 ;
	}
	//printList ( group ) ;//test code
    char * input = new char [ maximumCharArraySize ] ;
    if ( input == NULL )
    {
    	cout << "ERROR: The heap is full in main!" << endl ;
    	return 0 ;
    }
    bool goneThroughOnce ;
    Element * holderPtr = NULL ;
    int length ;
    do
    {
        goneThroughOnce = false ;
        cout << "Please enter an error to search for." << endl ;
        cin . getline ( input , maximumCharArraySize ) ;//Todo: make a function to parce the things between the ''s and the aka's.
        results = listSearch ( input , group ) ;
        if ( results == NULL )
        {
        	cout << "ERROR: listSearch returned NULL in main!" << endl ;
        }
        else
        {
        	length = results -> getLength ( ) ;
        	if ( length == 0 )
        	{
        	    cout << "No data matches the selection." << endl ;
        	}
        	else
        	{
        		if ( length == 1 )
        		{
        			cout << "There is one result." << endl ;
        		}
        		else
        		{//Todo: make it so that there is a choice to remove from the selection or select from it.
        			cout << "There are " << length << " results:" << endl ;
        		}
        		if ( ! printList ( * results ) )
        		{
        			cout << "ERROR: printList returned false in main!" << endl ;
        		}
        		if ( results -> getBeginning ( ) == NULL )
        		{
        			cout << "ERROR: getBeginning returned NULL in main from a non-empty list!" << endl ;
        		}
        		else
        		{
        			do
        			{
        				holderPtr = results -> getBeginning ( ) -> getData ( ) ;
        				//cout << "line 395" << endl ;//test code
        				if ( holderPtr == NULL )
        				{
        					cout << "ERROR: getData returned NULL in main!" << endl ;
        				}
        				else
        				{
        					if ( ! results -> deleteNode ( holderPtr ) )
        					{
        						cout << "ERROR: deleteNode returned false in main!" << endl ;
        					}
        				}
        			} while ( results -> getBeginning ( ) != NULL ) ;
        		}
        		delete results ;
        	}
        }
        for ( input [ 0 ] = '\0' ; strcmp ( input , "Yes" ) != 0 && strcmp ( input , "No" ) != 0 ; cin . getline ( input , maximumCharArraySize ) )
        {
            if ( goneThroughOnce )
            {
                cout << "Please only input an appropiate responce." << endl ;
            }
            else
            {
            	goneThroughOnce = true ;
            }
            cout << "Would you like to search again?(Yes/No)" << endl ;
        }
    } while ( strcmp ( input , "Yes" ) == 0 ) ;
    delete [ ] input ;
    input = NULL ;
	//cout << "line 427" << endl ;//test code
	return 0 ;
}
/* Antoine Labrecque */
