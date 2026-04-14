#ifndef MOVIECLASSHEADER_H
#define MOVIECLASSHEADER_H
#include "BaseMediaClassHeader.h"

class MovieClass: public BaseMedia
{
public:
    MovieClass();
    MovieClass(Type type, string name, double length, string date, int id, string actor1, string actor2, string director, string genre);
    ~MovieClass();

    string getDirector();
    void setDirector(string director);
    string getActor1();
    void setActor1(string actor1);
    string getActor2();
    void setActor2(string actor2);

private:
    string director;
    Type type;
    string name;
    double length;
    string date;
    int ID;
    string actor1;
    string actor2;
    string genre;
    bool available;
};

#endif
