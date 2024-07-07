// To write a C++ program to manipulate complex numbers using operator
// overloading. (addition,subtraction,multiplication,division)

#include <iostream>
using namespace std;

class complex
{
private:
    int real, img;

public:
    void get_input()
    {
        cout << "Enter the real part and imaginary part:" << endl;
        cin >> real >> img;
    }
    void display()
    {
        cout<< real << "+" << img << "i" << endl;
    }
    complex operator+(complex &c1)
    {
        complex c2;
        c2.real = real + c1.real;
        c2.img = img + c1.img;
        return c2;
    }
    complex operator-(complex &c1)
    {
        complex c2;
        c2.real = real - c1.real;
        c2.img = img - c1.img;
        return c2;
    }
    complex operator*(complex &c1)
    {
        complex c2;
        c2.real = real * c1.real;
        c2.img = img * c1.img;
        return c2;
    }
    complex operator/(complex &c1)
    {
        complex c2;
        c2.real = real / c1.real;
        c2.img = img / c1.img;
        return c2;
    }
};

int main()
{
    complex c1, c2, c3;
    c1.get_input();
    c2.get_input();
    cout << "C1+C2:";
    c3 = c1 + c2;
    c3.display();
    cout << "C1-C2:";
    c3 = c1 - c2;
    c3.display();

    cout << "C1*C2:";
    c3 = c1 * c2;
    c3.display();
    cout << "C1/C2:";
    c3 = c1 / c2;
    c3.display();
}