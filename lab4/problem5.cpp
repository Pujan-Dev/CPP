#include <iostream>
#include <cstring>
using namespace std;

class Inventory
{
private:
    int stock;        // number on hand
    int restock;      // reorder quantity
    double unitPrice; // price per unit
    char *itemDesc;   // description of item

public:
    Inventory(int s, int r, double u, const char *d)
    {
        stock = s;
        restock = r;
        unitPrice = u;
        itemDesc = new char[strlen(d) + 1];
        strcpy(itemDesc, d);
    }

    ~Inventory()
    {
        delete[] itemDesc;
    }

    void print()
    {
        cout << "Stock: " << stock << endl;
        cout << "Restock: " << restock << endl;
        cout << "Unit Price: $" << unitPrice << endl;
        cout << "Description: " << itemDesc << endl;
    }
};

// first derived class
class Auto : public Inventory
{
    char *brand;

public:
    Auto(int s, int r, double u, const char *d, const char *b) : Inventory(s, r, u, d)
    {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
    }

    ~Auto()
    {
        delete[] brand;
    }

    void print()
    {
        Inventory::print();
        cout << "Brand: " << brand << endl;
    }
};

// Second derived class
class Transmission : public Inventory
{
    char *supplier;

public:
    Transmission(int s, int r, double u, const char *d, const char *sup) : Inventory(s, r, u, d)
    {
        supplier = new char[strlen(sup) + 1];
        strcpy(supplier, sup);
    }

    ~Transmission()
    {
        delete[] supplier;
    }

    void print()
    {
        Inventory::print();
        cout << "Supplier: " << supplier << endl;
    }
};

int main()
{
    Auto Car(8, 3, 220.75, "A new car from Honda", "Honda");
    Car.print();
    cout << endl;
    Transmission Gearbox(30, 15, 250.99, "Gearbox from hari", "hari store");
    Gearbox.print();
    return 0;
}
