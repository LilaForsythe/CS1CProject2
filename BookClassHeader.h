#ifndef CS1CPROJECT2_BOOKCLASS_H
#define CS1CPROJECT2_BOOKCLASS_H

#include "BaseMediaClassHeader.h"
#include "AuthorInterface.h"

class BookClass : public BaseMedia,
                  public AuthorInterface
{
public:
    BookClass();
    BookClass(Type type, string name, double length, int date, int id, string author, string genre);
    virtual ~BookClass();

    virtual string getAuthor();
    virtual void setAuthor(string author);

    virtual void displayMediaInfo();

private:
    string author = "";
};

#endif
