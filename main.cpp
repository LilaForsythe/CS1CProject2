#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BaseMediaClassHeader.h"
#include "AudiobookClassHeader.h"
#include "MagazineClassHeader.h"
#include "MovieClassHeader.h"
using namespace std;

int main()
{
    ifstream fin;
    fin.open("Input.txt");

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
    string actor1;
    string actor2;
    string director;

    //vectors holding pieces of media
    vector<AudiobookClass> audiobooks;
    vector<MagazineClass> magazines;
    vector<MovieClass> movies;

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
            getline(fin, director, ',');
            fin.get();
            getline(fin, actor1, ',');
            fin.get();
            getline(fin, actor2, ',');
            fin.get();
            getline(fin, genre, ',');
            fin.get();
            getline(fin, available, '\n');

            MovieClass newMovie(option, name, length, date, id, actor1, actor2, director, genre);

            if (available == "available")
            {
                newMovie.setAvailable(true);
            }
            else if (available == "checked out")
            {
                newMovie.setAvailable(false);
            }

            movies.push_back(newMovie);
        }
        else if (type == "Album")
        {
            option = Album;
        }
    }
    fin.close();

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

    cout << endl << "Type Name Length Date ID Director Lead Actor 1 Lead Actor 2 Genre Availability" << endl;
    for (int i = 0; i < movies.size(); i++)
    {
        name = movies[i].getName();
        id = movies[i].getID();

        cout << "Movie" << " " << name << " " << movies[i].getLength() << " ";
        cout << movies[i].getDate() << " " << id << " " << movies[i].getDirector() << " ";
        cout << movies[i].getActor1() << " " << movies[i].getActor2() << " " << movies[i].getGenre() << " ";
        if (movies[i].isAvailable())
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