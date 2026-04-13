#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BaseMediaClassHeader.h"
#include "AudiobookClassHeader.h"
#include "MagazineClassHeader.h"
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
    int issue;

    //vector of vectors where each vector is a type of media
    //[0][i] holds books where [1][i] holds audiobooks
    //vector <vector<BaseMedia>> Library;

    vector<AudiobookClass> audiobooks;
    vector<MagazineClass> magazines;


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
            fin.get();
            getline(fin, name, ',');
            fin.get();
            fin >> length;
            fin.get();
            fin.get();
            getline(fin, date, ',');
            fin.get();
            fin >> id;
            fin.get();
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

            audiobooks.push_back(newAudiobook);
            //Library[1][index] = newAudiobook;
            index++;
        }
        else if (type == "Magazine")
        {
            option = Magazine;
            fin.get();
            getline(fin, name, ',');
            fin.get();
            fin >> length;
            fin.get();
            fin.get();
            getline(fin, date, ',');
            fin.get();
            fin >> id;
            fin.get();
            fin.get();
            getline(fin, author, ',');
            fin.get();
            fin >> issue;
            fin.get();
            fin.get();
            getline(fin, genre, ',');
            fin.get();
            getline(fin, available, '\n');

            MagazineClass newMagazine(option, name, length, date, id, author, issue, genre);

            if (available == "available")
            {
                newMagazine.setAvailable(true);
            }
            else if (available == "checked out")
            {
                newMagazine.setAvailable(false);
            }

            magazines.push_back(newMagazine);
        }
        else if (type == "Movie")
        {
            option = Movie;
        }
        else if (type == "Album")
        {
            option = Album;
        }
    }
    fin.close();


    /*for (int i = 0; i < 1; i++)
    {
        cout << Library[1][i].getName() << " " << Library[1][i].getLength() << endl;
    }*/

    cout << endl << "Type Name Length Date ID Author Narrator Genre Availability" << endl;
    for (int i = 0; i < audiobooks.size(); i++)
    {
        name = audiobooks[i].getName();
        id = audiobooks[i].getID();

        cout << "Audiobook" << " " << name << " " << audiobooks[i].getLength() << " ";
        cout << audiobooks[i].getDate() << " " << id << " " << audiobooks[i].getAuthor() << " ";
        cout << audiobooks[i].getNarrator() << " " << audiobooks[i].getGenre() << " ";
        if (audiobooks[i].isAvailable())
        {
            cout << "Available" << endl;
        }
        else
        {
            cout << "Checked Out" << endl;
        }
    }

    cout << endl << "Type Name Length Date ID Author Issue Genre Availability" << endl;
    for (int i = 0; i < magazines.size(); i++)
    {
        name = magazines[i].getName();
        id = magazines[i].getID();

        cout << "Magazine" << " " << name << " " << magazines[i].getLength() << " ";
        cout << magazines[i].getDate() << " " << id << " " << magazines[i].getAuthor() << " ";
        cout << magazines[i].getIssue() << " " << magazines[i].getGenre() << " ";
        if (magazines[i].isAvailable())
        {
            cout << "Available" << endl;
        }
        else
        {
            cout << "Checked Out" << endl;
        }
    }



    return 0;
}