#ifndef MANAGERCLASSHEADER_H
#define MANAGERCLASSHEADER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "BaseMediaClassHeader.h"
#include "BookClassHeader.h"
#include "AudiobookClassHeader.h"
#include "MagazineClassHeader.h"
#include "MovieClassHeader.h"

using namespace std;

class LibraryManager
{
public:
    LibraryManager();
    ~LibraryManager();

    void addItem(BaseMedia* item);
    void removeItemByID(int id);

    BaseMedia* searchByID(int id);
    BaseMedia* searchByName(const string& name);

    void checkOutItem(int id);
    void returnItem(int id);

    bool checkAvailability(int id);

    void displayAllMedia();
    void displayAvailableMedia();
    void displayCheckedOutMedia();
    void displayNumberOfEachType();

    void loadFromFile(const string& fileName);

private:
    vector<BaseMedia*> mediaList;

    string trim(const string& str);
};

#endif