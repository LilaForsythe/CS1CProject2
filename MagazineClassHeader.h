#ifndef MAGAZINECLASSHEADER_H
#define MAGAZINECLASSHEADER_H
#include "BaseMediaClassHeader.h"
#include "AuthorInterface.h"

class MagazineClass: public BaseMedia,
					 public AuthorInterface
{
public:
    MagazineClass();
    MagazineClass(Type type, string name, double length, int date, int id, string author, int issue, string genre);
    virtual ~MagazineClass();

    int getIssue();
    void setIssue(int issue);

    virtual string getAuthor();
    virtual void setAuthor(string author);
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
