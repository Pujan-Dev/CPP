#include <iostream>
using namespace std;

class Publication
{
    string pubTitle;
    float pubPrice;

public:
    void getInput()
    {
        cout << "Enter publication title and price: ";
        cin >> pubTitle >> pubPrice;
    }

    void display()
    {
        cout << "Title: " << pubTitle << endl;
        cout << "Price: Rs." << pubPrice << endl;
    }
};

class Book : public Publication
{
    int numberOfPages;

public:
    void getInput()
    {
        Publication::getInput();
        cout << "Enter number of pages: ";
        cin >> numberOfPages;
    }

    void display()
    {
        Publication::display();
        cout << "Number of Pages: " << numberOfPages << " pages" << endl;
    }
};

class Tape : public Publication
{
    float duration;

public:
    void getInput()
    {
        Publication::getInput();
        cout << "Enter duration (in minutes): ";
        cin >> duration;
    }

    void display()
    {
        Publication::display();
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

int main()
{
    Book bookInstance;
    Tape tapeInstance;

    bookInstance.getInput();
    tapeInstance.getInput();

    bookInstance.display();
    tapeInstance.display();

    return 0;
}
