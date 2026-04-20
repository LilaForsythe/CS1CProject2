#include "AudiobookClassHeader.h"
AudiobookClass::AudiobookClass()
{

}


AudiobookClass::AudiobookClass(Type type, string name, double length, int date, int id, string author, string narrator, string genre)
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

void AudiobookClass::displayMediaInfo()
{
    cout << "Audiobook " << "| " << setw(20) << this->getName() << "| ";

    int hrs = 0;
    int mins = 0;
    hrs = this->getLength();
    mins = (int(this->getLength() * 100)) % 100;

    cout << setw(2) << hrs << " hours & " << mins << " minutes" << " | " << this->getDate() << " | ";
    cout << setw(2) << this->getID() << " | " << setw(10) << this->getGenre() << "| " << setw(15);
    cout << this->getAuthor() << "| " << setw(15) << narrator << "| ";

    if (isAvailable())
    {
        cout << "Available" << endl;
    }
    else
    {
        throw BorrowedException("Audiobook");
    }
}