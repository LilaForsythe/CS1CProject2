#include "AudiobookClassHeader.h"
AudiobookClass::AudiobookClass()
{

}


AudiobookClass::AudiobookClass(Type type, string name, double length, string date, int id, string author, string narrator, string genre)
{
    setType(type);
    setName(name);
    setLength(length);
    setDate(date);
    setID(id);
    setAuthor(author);
    setNarrator(narrator);
    setGenre(genre);
}
AudiobookClass::~AudiobookClass()
{

}

string AudiobookClass::getNarrator()
{
    return narrator;
}
void AudiobookClass::setNarrator(string narrator)
{
    this->narrator = narrator;
}
