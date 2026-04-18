#ifndef CS1CPROJECT2_BOOKCLASS_H
#define CS1CPROJECT2_BOOKCLASS_H

#include "BaseMediaClass.h"

class BookClass : public BaseMedia
{
public:
    BookClass();
    BookClass(Type type, string name, double length, int date, int id, string author, string genre);
    ~BookClass();

    virtual void displayMediaInfo();
};

#endif
