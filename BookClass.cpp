#include "BookClassHeader.h"

BookClass::BookClass()
{
}

BookClass::BookClass(Type type, string name, double length, int date, int id, string author, string genre)
{
    setType(type);
    setName(name);
    setLength(length);
    setDate(date);
    setID(id);
    setAuthor(author);
    setGenre(genre);
}

BookClass::~BookClass()
{
}

string BookClass::getAuthor()
{
    return author;
}
void BookClass::setAuthor(string author)
{
    this->author = author;
}

void BookClass::displayMediaInfo()
{
    cout << setw(10) << "Book" << "| " << setw(20) << this->getName() << "| ";
    cout << setw(4) << this->getLength() << setw(18) << "pages " << "| ";
    cout << this->getDate() << " | ";
    cout << setw(2) << this->getID() << " | ";
    cout << setw(10) << this->getGenre() << "| ";
    cout << setw(15) << this->getAuthor() << "| ";

    if (isAvailable())
        cout << "Available" << endl;
    else
        throw BorrowedException("Book");
}
