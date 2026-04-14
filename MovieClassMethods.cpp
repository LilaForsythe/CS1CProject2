#include "movieClassHeader.h"

MovieClass::MovieClass()
{

}



MovieClass::MovieClass(Type type, string name, double length, string date, int id, string actor1, string actor2, string director, string genre)
{
    setType(type);
    setName(name);
    setLength(length);
    setDate(date);
    setID(id);
    setDirector(director);
    setActor1(actor1);
    setActor2(actor2);
    setGenre(genre);
}
MovieClass::~MovieClass()
{

}

string MovieClass::getActor1()
{
    return actor1;
}

void MovieClass::setActor1(string actor1)
{
    this -> actor1 = actor1;
}

string MovieClass::getActor2()
{
    return actor2;
}

void MovieClass::setActor2(string actor2)
{
    this -> actor2 = actor2;
}

string MovieClass::getDirector()
{
    return director;
}

void MovieClass::setDirector(string director)
{
    this -> director = director;
}
