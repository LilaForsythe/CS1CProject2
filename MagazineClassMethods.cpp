#include "MagazineClassHeader.h"

MagazineClass::MagazineClass()
{

}


MagazineClass::MagazineClass(Type type, string name, double length, int date, int id, string author, int issue, string genre)
{
    setType(type);
    setName(name);
    setLength(length);
    setDate(date);
    setID(id);
    setAuthor(author);
    setIssue(issue);
    setGenre(genre);
}
MagazineClass::~MagazineClass()
{

}

int MagazineClass::getIssue()
{
    return issue;
}

void MagazineClass::setIssue(int issue)
{
    this->issue = issue;
}

string MagazineClass::getAuthor()
{
    return author;
}
void MagazineClass::setAuthor(string author)
{
    this->author = author;
}

void MagazineClass::displayMediaInfo()
{
    cout << "Magazine" << " | " << setw(30) << this->getName() << "| " << setw(4) << this->getLength();
    cout << "pages | " << this->getDate() << " | " << setw(2) << this->getID() << " | " << setw(20);
    cout << this->getAuthor() << "| " << setw(5) << issue << " | " << setw(10) << this->getGenre() << "| ";
    if (isAvailable())
    {
        cout << "Available" << endl;
    }
    else
    {
        throw BorrowedException("Magazine");
    }
}
