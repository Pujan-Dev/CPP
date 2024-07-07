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

    float getAmount() const {
        return amount;
    }

    bool operator<(const NPR&) const;
    bool operator<=(const NPR&) const;
    bool operator==(const NPR&) const;
    bool operator>=(const NPR&) const;
    bool operator>(const NPR&) const;
    bool operator!=(const NPR&) const;
};

class NPR {
private:
    float amount;

public:
    void getInput() {
        cout << "Enter the currency in NPR: ";
        cin >> amount;
    }

    float getAmount() const {
        return amount;
    }

    bool operator<(const USD&) const;
    bool operator<=(const USD&) const;
    bool operator==(const USD&) const;
    bool operator>=(const USD&) const;
    bool operator>(const USD&) const;
    bool operator!=(const USD&) const;
};

const float conversionRate = 101.36;

bool USD::operator<(const NPR& npr) const {
    return amount < npr.getAmount() / conversionRate;
}

bool USD::operator<=(const NPR& npr) const {
    return amount <= npr.getAmount() / conversionRate;
}

bool USD::operator==(const NPR& npr) const {
    return amount == npr.getAmount() / conversionRate;
}

bool USD::operator>=(const NPR& npr) const {
    return amount >= npr.getAmount() / conversionRate;
}

bool USD::operator>(const NPR& npr) const {
    return amount > npr.getAmount() / conversionRate;
}

bool USD::operator!=(const NPR& npr) const {
    return amount != npr.getAmount() / conversionRate;
}

bool NPR::operator<(const USD& usd) const {
    return amount < usd.getAmount() * conversionRate;
}

bool NPR::operator<=(const USD& usd) const {
    return amount <= usd.getAmount() * conversionRate;
}

bool NPR::operator==(const USD& usd) const {
    return amount == usd.getAmount() * conversionRate;
}

bool NPR::operator>=(const USD& usd) const {
    return amount >= usd.getAmount() * conversionRate;
}

bool NPR::operator>(const USD& usd) const {
    return amount > usd.getAmount() * conversionRate;
}

bool NPR::operator!=(const USD& usd) const {
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
