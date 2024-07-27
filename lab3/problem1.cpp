#include <iostream>
#include <iomanip> // for std::fixed and std::setprecision

using namespace std;

class Converter
{
private:
    float nep;
    float us = 98.51; // 1$ = NRS.98.51;

public:
    Converter() : nep(0) {}
    Converter(float rs) : nep(rs) {}
    
    void input()
    {
        cin >> nep;
    }

    float convert()
    {
        return (nep / us);
    }
};

int main()
{
    Converter n1;
    cout << "Enter amount in Nepalese Rupees: ";
    n1.input();
    float usd = n1.convert();

    int dollars = static_cast<int>(usd);
    int cents = static_cast<int>((usd - dollars) * 100);

    cout << "Converted amount is: " << dollars << " dollars and " << cents << " cents" << endl;

    return 0;
}
