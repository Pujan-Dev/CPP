#include <iostream>
using namespace std;

class c2;

class c1 {
private:
    int a;
    float b;

public:
    friend void swap(c1&, c2&);
    void getInput() {
        cout << "Enter an integer and a float for c1: ";
        cin >> a >> b;
    }
    void display() const {
        cout << "c1 - a = " << a << ", b = " << b << endl;
    }
};

class c2 {
private:
    int a;
    float b;

public:
    friend void swap(c1&, c2&);
    void getInput() {
        cout << "Enter an integer and a float for c2: ";
        cin >> a >> b;
    }
    void display() const {
        cout << "c2 - a = " << a << ", b = " << b << endl;
    }
};

void swap(c1& p, c2& q) {
    int tempInt = p.a;
    p.a = q.a;
    q.a = tempInt;

    float tempFloat = p.b;
    p.b = q.b;
    q.b = tempFloat;
}

int main() {
    c1 firstMem;
    c2 secondMem;

    firstMem.getInput();
    secondMem.getInput();

    cout << "\nBefore swapping:" << endl;
    firstMem.display();
    secondMem.display();

    swap(firstMem, secondMem);

    cout << "\nAfter swapping:" << endl;
    firstMem.display();
    secondMem.display();

    return 0;
}
