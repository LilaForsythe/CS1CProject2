#include "MagazineClassHeader.h"

MagazineClass::MagazineClass()
{

}


MagazineClass::MagazineClass(Type type, string name, double length, int date, int id, string author, double issue, string genre)
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

double MagazineClass::getIssue()
{
    return issue;
}

void MagazineClass::setIssue(double issue)
{
    this->issue = issue;
}

void MagazineClass::displayMediaInfo()
{
    cout << "Magazine"<< "  | "<< setw(20)<< this->getName()<< "| "<< setw(4)<< this->getLength() << setw(18);
    cout << "pages" << "| " << this->getDate() << " | " << setw(2) << this->getID() << " | " << setw(10);
    cout << this->getGenre() << "| "<< setw(15) << this->getAuthor() << "| ";
    int vol = 0;
    int iss = 0;
    this->setIssue(issue+0.0001);
    vol = issue;
    iss = (int(issue * 100)) % 100;
    cout << "vol " << vol << " issue " << setw (3) << iss << "| ";
    if (isAvailable())
    {
        cout << "Available" << endl;
    }
    else
    {
        throw BorrowedException("Magazine");
    }
}