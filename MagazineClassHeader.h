#ifndef MAGAZINECLASSHEADER_H
#define MAGAZINECLASSHEADER_H
#include "BaseMediaClassHeader.h"

class MagazineClass: public BaseMedia
{
public:
    MagazineClass();
    MagazineClass(Type type, string name, double length, int date, int id, string author, int issue, string genre);
    ~MagazineClass();

    int getIssue();
    void setIssue(int issue);

    virtual void displayMediaInfo();
private:
    int issue = 0;
    Type type;
    string name = "";
    double length = 0.0;
    int date = 0;
    int ID = 0;
    string author = "";
    string genre = "";
    bool available = false;
};

#endif
