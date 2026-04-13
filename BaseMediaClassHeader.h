#ifndef BASEMEDIACLASSHEADER_H
#define BASEMEDIACLASSHEADER_H
#include <string>
#include <iostream>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};
enum Type
{
    Book,
    Audiobook,
    Magazine,
    Movie,
    Album
};
class BaseMedia
{
    public:
    BaseMedia();
    BaseMedia(Type type, string name, double length, string date, int id, string author, string genre);
    ~BaseMedia();

    string getName();     //Returns the name of the media
    void setName(string name);  //Sets a new name for the media

    Type getType();
    void setType(Type type);

    double getLength();
    void setLength(double length);

    string getDate();
    void setDate(string date);

    int getID();
    void setID(int id);

    string getAuthor();
    void setAuthor(string author);

    string getGenre();
    void setGenre(string genre);

    bool isAvailable();
    void setAvailable(bool available);

    //virtual void displayMediaInfo() = 0;

private:
    string name = "";
    Type mediaType;
    double length = 0.0;
    string date;
    //Date date = {0,0,0};
    int ID = 0;
    string author = "";
    string genre = "";
    bool available = true;
};
#endif