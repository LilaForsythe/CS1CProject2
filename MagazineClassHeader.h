#ifndef MAGAZINECLASSHEADER_H
#define MAGAZINECLASSHEADER_H
#include "BaseMediaClassHeader.h"

class MagazineClass: public BaseMedia
{
public:
    MagazineClass();
    MagazineClass(Type type, string name, double length, string date, int id, string author, int issue, string genre);
    ~MagazineClass();

    int getIssue();
    void setIssue(int issue);

private:
    int issue = 0;
    Type type;
    string name;
    double length;
    string date;
    int ID;
    string author;
    string genre;
    bool available;
};

#endif
