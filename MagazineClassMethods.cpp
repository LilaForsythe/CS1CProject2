#include "MagazineClassHeader.h"

MagazineClass::MagazineClass()
{

}


MagazineClass::MagazineClass(Type type, string name, double length, string date, int id, string author, int issue, string genre)
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
