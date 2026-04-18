#ifndef MOVIECLASSHEADER_H
#define MOVIECLASSHEADER_H
#include "BaseMediaClassHeader.h"

class MovieClass: public BaseMedia
{
public:
    MovieClass();
    MovieClass(Type type, string name, double length, int date, int id, string actor1, string actor2, string director, string genre);
    ~MovieClass();

    string getDirector();
    void setDirector(string director);
    string getActor1();
    void setActor1(string actor1);
    string getActor2();
    void setActor2(string actor2);

    virtual void displayMediaInfo();
private:
    string director = "";
    Type type;
    string name = "";
    double length = 0.0;
    int date = 0;
    int ID = 0;
    string actor1 = "";
    string actor2 = "";
    string genre = "";
    bool available = false;
};

#endif
