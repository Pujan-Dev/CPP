#include <iostream>

using namespace std;

class NPR;  // Forward declaration

class USD {
private:
    float amount;

public:
    void getInput() {
        cout << "Enter the currency in USD: ";
        cin >> amount;
    }

    float getAmount()   {
        return amount;
    }

    bool operator<(  NPR&)  ;
    bool operator<=(  NPR&)  ;
    bool operator==(  NPR&)  ;
    bool operator>=(  NPR&)  ;
    bool operator>(  NPR&)  ;
    bool operator!=(  NPR&)  ;
};

class NPR {
private:
    float amount;

public:
    void getInput() {
        cout << "Enter the currency in NPR: ";
        cin >> amount;
    }

    float getAmount()   {
        return amount;
    }

    bool operator<(  USD&)  ;
    bool operator<=(  USD&)  ;
    bool operator==(  USD&)  ;
    bool operator>=(  USD&)  ;
    bool operator>(  USD&)  ;
    bool operator!=(  USD&)  ;
};

  float conversionRate = 101.36;

bool USD::operator<(  NPR& npr)   {
    return amount < npr.getAmount() / conversionRate;
}

bool USD::operator<=(  NPR& npr)   {
    return amount <= npr.getAmount() / conversionRate;
}

bool USD::operator==(  NPR& npr)   {
    return amount == npr.getAmount() / conversionRate;
}

bool USD::operator>=(  NPR& npr)   {
    return amount >= npr.getAmount() / conversionRate;
}

bool USD::operator>(  NPR& npr)   {
    return amount > npr.getAmount() / conversionRate;
}

bool USD::operator!=(  NPR& npr)   {
    return amount != npr.getAmount() / conversionRate;
}

bool NPR::operator<(  USD& usd)   {
    return amount < usd.getAmount() * conversionRate;
}

bool NPR::operator<=(  USD& usd)   {
    return amount <= usd.getAmount() * conversionRate;
}

bool NPR::operator==(  USD& usd)   {
    return amount == usd.getAmount() * conversionRate;
}

bool NPR::operator>=(  USD& usd)   {
    return amount >= usd.getAmount() * conversionRate;
}

bool NPR::operator>(  USD& usd)   {
    return amount > usd.getAmount() * conversionRate;
}

bool NPR::operator!=(  USD& usd)   {
    return amount != usd.getAmount() * conversionRate;
}

int main() {
    USD usd;
    NPR npr;

    usd.getInput();
    npr.getInput();

    cout << "Comparing USD and NPR:" << endl;
    cout << "USD < NPR: " << (usd < npr) << endl;
    cout << "USD > NPR: " << (usd > npr) << endl;
    cout << "USD <= NPR: " << (usd <= npr) << endl;
    cout << "USD >= NPR: " << (usd >= npr) << endl;
    cout << "USD == NPR: " << (usd == npr) << endl;
    cout << "USD != NPR: " << (usd != npr) << endl;

    return 0;
}
