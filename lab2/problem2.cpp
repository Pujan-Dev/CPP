#include <iostream>

using namespace std;

class USD;  // Forward declaration

class NPR {
private:
    float amount;

public:
    void getInput() {
        cout << "Enter the currency in NPR: ";
        cin >> amount;
    }

    float getAmount() {
        return amount;
    }

    friend bool operator<(  NPR& npr,   USD& usd);
    friend bool operator<=(  NPR& npr,   USD& usd);
    friend bool operator==(  NPR& npr,   USD& usd);
    friend bool operator>=(  NPR& npr,   USD& usd);
    friend bool operator>(  NPR& npr,   USD& usd);
    friend bool operator!=(  NPR& npr,   USD& usd);
};

class USD {
private:
    float amount;

public:
    void getInput() {
        cout << "Enter the currency in USD: ";
        cin >> amount;
    }

    float getAmount() {
        return amount;
    }

    friend bool operator<(  NPR& npr,   USD& usd);
    friend bool operator<=(  NPR& npr,   USD& usd);
    friend bool operator==(  NPR& npr,   USD& usd);
    friend bool operator>=(  NPR& npr,   USD& usd);
    friend bool operator>(  NPR& npr,   USD& usd);
    friend bool operator!=(  NPR& npr,   USD& usd);
};

float conversionRate = 101.36;

bool operator<(  NPR& npr,   USD& usd) {
    return npr.amount < usd.amount * conversionRate;
}

bool operator<=(  NPR& npr,   USD& usd) {
    return npr.amount <= usd.amount * conversionRate;
}

bool operator==(  NPR& npr,   USD& usd) {
    return npr.amount == usd.amount * conversionRate;
}

bool operator>=(  NPR& npr,   USD& usd) {
    return npr.amount >= usd.amount * conversionRate;
}

bool operator>(  NPR& npr,   USD& usd) {
    return npr.amount > usd.amount * conversionRate;
}

bool operator!=(  NPR& npr,   USD& usd) {
    return npr.amount != usd.amount * conversionRate;
}

int main() {
    USD usd;
    NPR npr;

    usd.getInput();
    npr.getInput();

    cout << "Comparing USD and NPR:" << endl;
    cout << "USD < NPR: " << (npr< usd) << endl;
    cout << "USD > NPR: " << (npr>usd) << endl;
    cout << "USD <= NPR: " << (npr<= usd) << endl;
    cout << "USD >= NPR: " << (npr>= usd) << endl;
    cout << "USD == NPR: " << (npr== usd) << endl;
    cout << "USD != NPR: " << (npr!= usd) << endl;

    return 0;
}
