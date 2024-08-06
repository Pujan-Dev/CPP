#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
class cart
{
private:
    double x, y;

public:
    cart() : x(0), y(0) {};
    cart(double x1, double y1) : x(x1), y(y1) {};
    void display()
    {
        cout << fixed << setprecision(2);

        cout << "Cartesian coordinates are: (" << x << ", " << y << ")." << endl;
    }
    void input()
    {

        cout << "Enter the value of x and y: " << endl;
        cin >> x >> y;
    }
    double x_return()
    {
        return x;
    }
    double y_return()
    {
        return y;
    }

};

class polar
{
private:
    double r, theta;

public:
    polar() : r(0), theta(0) {}
    polar(double R, double THETA) : r(R), theta(THETA) {}
    void input()
    {

        cout << "Enter the value of r and theta (in radian): " << endl;
        cin >> r >> theta;
    }
    double returntheta()
    {
        return theta;
    }
    double return_r()
    {
        return r;
    }
    void display()
    {
        theta= theta*(180.0/M_PI);
        cout << "polar coordinates are: (" << r << ", " << theta << ")." << endl;
    }
    polar(cart& c1)
    {
        double x = c1.x_return();
        double y = c1.y_return();
        r = sqrt(x * x + y * y);
        theta = atan2(y, x);
    }
};

int main()
{
    cart C1;
    C1.input();
    polar p1 = C1;
    p1.display();
    return 0;
}
