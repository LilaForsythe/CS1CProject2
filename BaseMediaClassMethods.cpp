#include "BaseMediaClassHeader.h"
BaseMedia::BaseMedia()
{

}

BaseMedia::BaseMedia(Type type, string name, double length, int date, int id, string author, string genre)
{
    setType(type);
    setName(name);
    setLength(length);
    setDate(date);
    setID(id);
    setGenre(genre);
    setAvailable(available);
}

BaseMedia::~BaseMedia()
{

}


string BaseMedia::getName()
{
    return name;
}
void BaseMedia::setName(string name)
{
    this->name = name;
}

Type BaseMedia::getType()
{
    return mediaType;
}
void BaseMedia::setType(Type type)
{
    this->mediaType = type;
}

double BaseMedia::getLength()
{
    return length;
}
void BaseMedia::setLength(double length)
{
    this->length = length;
}

int BaseMedia::getDate()
{
    return date;
}
void BaseMedia::setDate(int date)
{
    this->date = date;
}

int BaseMedia::getID()
{
    return ID;
}
void BaseMedia::setID(int id)
{
    this->ID = id;
}

string BaseMedia::getGenre()
{
    return genre;
}

void BaseMedia::setGenre(string genre)
{
    this->genre = genre;
}

bool BaseMedia::isAvailable()
{
    return available;
}
void BaseMedia::setAvailable(bool available)
{
    this->available = available;
}
