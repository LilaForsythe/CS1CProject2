#include "LibraryManagerClassHeader.h"

LibraryManager::LibraryManager()
{
}

LibraryManager::~LibraryManager()
{
    for (int i = 0; i < mediaList.size(); i++)
    {
        delete mediaList[i];
    }
    mediaList.clear();
}

void LibraryManager::addItem(BaseMedia* item)
{
    mediaList.push_back(item);
}

void LibraryManager::removeItemByID(int id)
{
    for (int i = 0; i < mediaList.size(); i++)
    {
        if (mediaList[i]->getID() == id)
        {
            delete mediaList[i];
            mediaList.erase(mediaList.begin() + i);
            return;
        }
    }

    throw "Error: item not found.";
}

BaseMedia* LibraryManager::searchByID(int id)
{
    for (int i = 0; i < mediaList.size(); i++)
    {
        if (mediaList[i]->getID() == id)
        {
            return mediaList[i];
        }
    }

    return nullptr;
}

BaseMedia* LibraryManager::searchByName(const string& name)
{
    for (int i = 0; i < mediaList.size(); i++)
    {
        if (mediaList[i]->getName() == name)
        {
            return mediaList[i];
        }
    }

    return nullptr;
}

void LibraryManager::checkOutItem(int id)
{
    BaseMedia* item = searchByID(id);

    if (item == nullptr)
    {
        throw "Error: item not found.";
    }

    if (!item->isAvailable())
    {
        throw "Error: item already checked out.";
    }

    item->setAvailable(false);
}

void LibraryManager::returnItem(int id)
{
    BaseMedia* item = searchByID(id);

    if (item == nullptr)
    {
        throw "Error: item not found.";
    }

    if (item->isAvailable())
    {
        throw "Error: item was not checked out.";
    }

    item->setAvailable(true);
}

bool LibraryManager::checkAvailability(int id)
{
    BaseMedia* item = searchByID(id);

    if (item == nullptr)
    {
        throw "Error: item not found.";
    }

    return item->isAvailable();
}

void LibraryManager::displayAllMedia()
{
    cout << "\n**************** ALL MEDIA ****************\n";

    for (int i = 0; i < mediaList.size(); i++)
    {
        try
        {
            mediaList[i]->displayMediaInfo();
        }
        catch (const BorrowedException& e)
        {
            cout << mediaList[i]->getName() << " - " << e.what() << endl;
        }
    }
}

void LibraryManager::displayAvailableMedia()
{
    cout << "\n**************** AVAILABLE MEDIA ****************\n";

    cout << endl << left << setw(9) << "Type" << " | " << setw(20) << "Name" << "| " << setw(10) << "Length";
    cout << "| " << "Date" << " | " << "ID" << " | " << setw(15) << "Author";
    cout << "| " << setw(10) << "Genre" << "| " << setw(12) << "Availability" << endl;
    cout << setfill('-') << setw(105) << "" << endl << setfill(' ');

    for (int i = 0; i < mediaList.size(); i++)
    {
        if (mediaList[i]->isAvailable())
        {
            try
            {
                mediaList[i]->displayMediaInfo();
            }
            catch (const BorrowedException& e)
            {
                cout << mediaList[i]->getName() << " - " << e.what() << endl;
            }
        }
    }
}

void LibraryManager::displayCheckedOutMedia()
{
    cout << "\n**************** CHECKED OUT MEDIA ****************\n";

    for (int i = 0; i < mediaList.size(); i++)
    {
        if (!mediaList[i]->isAvailable())
        {
            try
            {
                mediaList[i]->displayMediaInfo();
            }
            catch (const BorrowedException& e)
            {
                cout << mediaList[i]->getName() << " - " << e.what() << endl;
            }
        }
    }
}

void LibraryManager::displayNumberOfEachType()
{
    int bookCount = 0;
    int audiobookCount = 0;
    int magazineCount = 0;
    int movieCount = 0;
    int albumCount = 0;

    for (int i = 0; i < mediaList.size(); i++)
    {
        switch (mediaList[i]->getType())
        {
        case Book:
            bookCount++;
            break;
        case Audiobook:
            audiobookCount++;
            break;
        case Magazine:
            magazineCount++;
            break;
        case Movie:
            movieCount++;
            break;
        case Album:
            albumCount++;
            break;
        }
    }

    cout << "\n**************** MEDIA COUNTS ****************\n";
    cout << "Books: " << bookCount << endl;
    cout << "Audiobooks: " << audiobookCount << endl;
    cout << "Magazines: " << magazineCount << endl;
    cout << "Movies: " << movieCount << endl;
    cout << "Albums: " << albumCount << endl;
}

string LibraryManager::trim(const string& str)
{
    int start = 0;
    while (start < str.length() && str[start] == ' ')
    {
        start++;
    }

    int end = str.length() - 1;
    while (end >= 0 && str[end] == ' ')
    {
        end--;
    }

    if (start > end)
    {
        return "";
    }

    return str.substr(start, end - start + 1);
}

void LibraryManager::loadFromFile(const string& fileName)
{
    ifstream fin(fileName);

    if (!fin)
    {
        throw FileOpenException(fileName);
    }

    string line;

    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }

        vector<string> fields;
        string current = "";

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ',')
            {
                fields.push_back(trim(current));
                current = "";
            }
            else
            {
                current += line[i];
            }
        }
        fields.push_back(trim(current));

        string type = fields[0];

        try
        {
            if (type == "Book" && fields.size() >= 8)
            {
                BookClass* newBook = new BookClass(
                    Book,
                    fields[1],
                    stod(fields[2]),
                    stoi(fields[3]),
                    stoi(fields[4]),
                    fields[5],
                    fields[6]
                );

                newBook->setAvailable(fields[7] == "available");
                addItem(newBook);
            }
            else if (type == "Audiobook" && fields.size() >= 9)
            {
                AudiobookClass* newAudiobook = new AudiobookClass(
                    Audiobook,
                    fields[1],
                    stod(fields[2]),
                    stoi(fields[3]),
                    stoi(fields[4]),
                    fields[5],
                    fields[6],
                    fields[7]
                );

                newAudiobook->setAvailable(fields[8] == "available");
                addItem(newAudiobook);
            }
            else if (type == "Magazine" && fields.size() >= 9)
            {
                MagazineClass* newMagazine = new MagazineClass(
                    Magazine,
                    fields[1],
                    stod(fields[2]),
                    stoi(fields[3]),
                    stoi(fields[4]),
                    fields[5],
                    stoi(fields[6]),
                    fields[7]
                );

                newMagazine->setAvailable(fields[8] == "available");
                addItem(newMagazine);
            }
            else if (type == "Movie" && fields.size() >= 10)
            {
                MovieClass* newMovie = new MovieClass(
                    Movie,
                    fields[1],
                    stod(fields[2]),
                    stoi(fields[3]),
                    stoi(fields[4]),
                    fields[6],
                    fields[7],
                    fields[5],
                    fields[8]
                );

                newMovie->setAvailable(fields[9] == "available");
                addItem(newMovie);
            }
            else if (type == "Album")
            {
                // skip albums for now since no Album class is implemented
                continue;
            }
            else
            {
                throw MediaTypeException(type);
            }
        }
        catch (const MediaTypeException& t)
        {
            cout << t.what() << "Skipping this library entry.\n";
        }
    }

    fin.close();
}