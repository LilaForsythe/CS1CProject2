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
    int date;
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
            fin >> date;
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
            fin >> date;
            fin.get();
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
            fin >> date;
            fin.get();
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

    //eventually the manager class will do this
    //display all audiobooks
    //displaying the header
    cout << endl << left << setw(9) << "Type" << " | " << setw(20) << "Name" << "| " <<setw(22) << "Length";
    cout << "| " << "Date" << " | " << "ID" << " | " << setw(15) << "Author" << "| " << setw(15) << "Narrator";
    cout << "| " << setw(10) << "Genre" << "| " << setw(12) << "Availability" << endl;
    cout << setfill('-') << setw(129) << "" << endl << setfill(' ');

    //displaying the media
    for (int i = 0; i < audiobooks.size(); i++)
    {
        audiobooks[i].displayMediaInfo();
    }

    //display all magazines
    //displaying the header
    cout << endl << left << setw(8) << "Type" << " | " << setw(30) << "Name" << "| " <<setw(10) << "Length";
    cout << "| " << "Date" << " | " << "ID" << " | " << setw(20) << "Author" << "| " << "Issue";
    cout << " | " << setw(10) << "Genre" << "| " << setw(12) << "Availability" << endl;
    cout << setfill('-') << setw(122) << "" << endl << setfill(' ');

    //displaying the media
    for (int i = 0; i < magazines.size(); i++)
    {
        magazines[i].displayMediaInfo();
    }

    //display all movies
    //displaying the header
    cout << endl << left << setw(6) << "Type" << "| " << setw(20) << "Name" << "| " <<setw(21) << "Length";
    cout << "| " << "Date" << " | " << "ID" << " | " << setw(15) << "Director" << "| " << setw(15) << "Lead 1";
    cout << "| " << setw(15) << "Lead 2" << "| " << setw(15) << "Genre" << "| " << setw(12);
    cout << "Availability" << endl;
    cout << setfill('-') << setw(147) << "" << endl << setfill(' ');

    //displaying the media
    for (int i = 0; i < movies.size(); i++)
    {
        movies[i].displayMediaInfo();
    }

    return 0;
}