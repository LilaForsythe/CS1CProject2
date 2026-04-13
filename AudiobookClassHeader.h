#ifndef AUDIOBOOKCLASSHEADER_H
#define AUDIOBOOKCLASSHEADER_H
#include "BaseMediaClassHeader.h"

class AudiobookClass: public BaseMedia
{
public:
    AudiobookClass();
    AudiobookClass(Type type, string name, double length, string date, int id, string author, string narrator, string genre);
    ~AudiobookClass();

    /*string getName();
    void setName(string name);

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
*/
    string getNarrator();
    void setNarrator(string narrator);
/*
    string getGenre();
    void setGenre(string genre);

    bool isAvailable();
    void setAvailable(bool available);
*/
private:
    Type type;
    string name;
    double length;
    string date;
    int ID;
    string author;
    string narrator;
    string genre;
    bool available;
};
#endif