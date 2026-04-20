#ifndef AUTHORINTERFACE_H_
#define AUTHORINTERFACE_H_

#include <iostream>
#include <string>
using namespace std;

/***************************************************************************
 * AuthorInterface
 * -------------------------------------------------------------------------
 *		This is an abstract class used to define virtual functions to
 *		retrieve or assign the name of the author to a piece of media.
 *		Classes that utilize this interface will be able to define how
 *		the name of the author will be assigned and retrieved.
 **************************************************************************/

class AuthorInterface
{
	public:
		AuthorInterface() {};
		virtual ~AuthorInterface() {};

		virtual string getAuthor() = 0;
		virtual void setAuthor(string author) = 0;
};

#endif /* AUTHORINTERFACE_H_ */
