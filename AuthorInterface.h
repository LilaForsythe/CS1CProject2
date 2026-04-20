#ifndef AUTHORINTERFACE_H_
#define AUTHORINTERFACE_H_

#include <iostream>
#include <string>
using namespace std;

/***************************************************************************
 * AuthorInterface
 * -------------------------------------------------------------------------
 *		This is an abstract class used to define pure virtual functions to
 *		retrieve or assign the name of the author to a piece of media.
 *		Classes that utilize this interface will be able to define how
 *		the name of the author will be assigned and retrieved.
 **************************************************************************/

class AuthorInterface
{
public:
    AuthorInterface() {};          //No-arg constructor
    virtual ~AuthorInterface() {}; //Virtual Destructor

    virtual string getAuthor() = 0;            //Retrieves Author's name
    virtual void setAuthor(string author) = 0; //Sets Author's name
};

#endif /* AUTHORINTERFACE_H_ */
