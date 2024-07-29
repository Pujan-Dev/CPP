#include <iostream>
using namespace std;

class Publication
{
    string pubTitle;
    float pubPrice;

public:
    void getInput()
    {
        cout << "Enter publication title and price in USD: ";
        cin >> pubTitle >> pubPrice;
    }

    void display()
    {
        float priceInNPR = pubPrice * 120; // Conversion rate: 1 USD = 120 NPR
        cout << "Title: " << pubTitle << endl;
        cout << "Price: Rs." << priceInNPR << endl;
    }
};

class Sales
{
    float sales[3];

public:
    void getdata()
    {
        cout << "Enter sales for the last three months in USD: ";
        for (int i = 0; i < 3; i++)
        {
            cin >> sales[i];
        }
    }

    void putdata()
    {
        cout << "Sales for the last three months: ";
        for (int i = 0; i < 3; i++)
        {
            float salesInNPR = sales[i] * 120; // Conversion rate: 1 USD = 120 NPR
            cout << salesInNPR << " Rs ";
        }
        cout << endl;
    }
};

class Book : public Publication, public Sales
{
    int numberOfPages;

public:
    void getInput()
    {
        Publication::getInput();
        Sales::getdata();
        cout << "Enter number of pages: ";
        cin >> numberOfPages;
    }

    void display()
    {
        Publication::display();
        Sales::putdata();
        cout << "Number of Pages: " << numberOfPages << " pages" << endl;
    }
};

class Tape : public Publication, public Sales
{
    float duration;

public:
    void getInput()
    {
        Publication::getInput();
        Sales::getdata();
        cout << "Enter duration (in minutes): ";
        cin >> duration;
    }

    void display()
    {
        Publication::display();
        Sales::putdata();
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
