
#ifndef CS1CPROJECT2_AUDIOBOOKCLASS_H
#define CS1CPROJECT2_AUDIOBOOKCLASS_H
#include "BaseMediaClass.h"
using namespace std;

class AudiobookClass: public BaseMedia
{
public:
    AudiobookClass();
    AudiobookClass(Type type, string name, double length, int date, int id, string author, string narrator, string genre);
    ~AudiobookClass();

    string getNarrator();
    void setNarrator(string narrator);

    virtual void displayMediaInfo();

private:
    Type type;
    string name ="";
    double length = 0.0;
    int date = 0;
    int ID = 0;
    string author = "";
    string narrator = "";
    string genre = "";
    bool available = "";
};

#endif //CS1CPROJECT2_AUDIOBOOKCLASS_H
