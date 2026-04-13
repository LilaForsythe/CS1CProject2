#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BaseMediaClassHeader.h"
#include "AudiobookClassHeader.h"
//#include "BaseMediaClassMethods.cpp"
//#include "AudiobookClassMethods.cpp"
using namespace std;

int main()
{
    ifstream fin;
    fin.open("Input.txt");

    //number of that type of media
    int index = 0;

    string type;
    Type option;
    string name;
    double length;
    string date;
    int id;
    string author;
    string narrator;
    string genre;
    string available;

    //vector of vectors where each vector is a type of media
    //[0][i] holds books where [1][i] holds audiobooks
    vector <vector<BaseMedia>> Library;

    while (!fin.eof())
    {
        //reading in type
        getline(fin, type, ',');
        //reading in the rest
        if (type == "Book")
        {
            option = Book;
        }
        else if (type == "Audiobook")
        {
            option = Audiobook;
            getline(fin, name, ',');
            fin >> length;
            fin.get();
            getline(fin, date, ',');
            fin >> id;
            fin.get();
            getline(fin, author, ',');
            fin.get();
            getline(fin, narrator, ',');
            fin.get();
            getline(fin, genre, ',');
            fin.get();
            getline(fin, available, '\n');

            AudiobookClass newAudiobook(option, name, length, date, id, author, narrator, genre);

            if (available == "available")
            {
                newAudiobook.setAvailable(true);
            }
            else if (available == "checked out")
            {
                newAudiobook.setAvailable(false);
            }

            Library[1][index] = newAudiobook;
            index++;
        }
        else if (type == "Magazine")
        {
            option = Magazine;
        }
        else if (type == "Movie")
        {
            option = Movie;
        }
    }
    fin.close();


    for (int i = 0; i < 1; i++)
    {
        cout << Library[1][i].getName() << " " << Library[1][i].getLength() << endl;
    }



    return 0;
}