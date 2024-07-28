#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class ConvertCtoP {
private:
    float r, theta;
    float x, y;

public:
    ConvertCtoP() : x(0), y(0), r(0), theta(0) {}
    ConvertCtoP(float X, float Y) : x(X), y(Y), r(0), theta(0) {}

    void input() {
        cout << "Enter the value of x and y (x,y): " << endl;
        cin >> x >> y;
    }

    void convert() {
        r = sqrt(x * x + y * y);
        theta = atan2(y, x);  // atan2 is better for handling all quadrants
    }

    void display() {
        const float pi = 3.14159265358979323846;
        cout << fixed << setprecision(2);
        theta = (180 / pi) * theta;
        cout << "Polar coordinates are: (" << r << ", " << theta << " degrees)." << endl;
    }
};

int main() {
    ConvertCtoP p1;
    p1.input();
    p1.convert();
    p1.display();
    return 0;
}
