#include "movieClassHeader.h"

MovieClass::MovieClass()
{

}



MovieClass::MovieClass(Type type, string name, double length, int date, int id, string actor1, string actor2, string director, string genre)
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

void MovieClass::displayMediaInfo()
{
    cout << "Movie " << "| " << setw(20) << this->getName() << "| ";

    int hrs = 0;
    int mins = 0;
    this->setLength(this->getLength()+0.0001);
    hrs = this->getLength();
    mins = (int(this->getLength() * 100)) % 100;

    cout << hrs << " hours & " << setw(2) << mins << " minutes" << " | " << this->getDate() << " | ";
    cout << setw(2) << this->getID() << " | " << setw(15) << director << "| " << setw(15);
    cout << actor1 << "| " << setw(15) << actor2 << "| " << setw(15) << this->getGenre() << "| ";

    if (isAvailable())
    {
        cout << "Available" << endl;
    }
    else
    {
        cout << "Checked Out" << endl;
    }
}
