#include <iostream>
#include <cmath>
#include <iomanip>  
using namespace std;

class ConvertPtoC {
private:
    float r, theta;
    float x, y;

public:
    ConvertPtoC() : r(0), theta(0) {}
    ConvertPtoC(float R, float THETA) : r(R), theta(THETA) {}

    void input() {
        cout << "Enter the value of r and theta (in degrees): " << endl;
        cin >> r >> theta;
    }

    void convert() {
        float thetaRad = theta * (M_PI / 180.0); 
        x = r * cos(thetaRad);
        y = r * sin(thetaRad);
    }

    void display() {
        cout << fixed << setprecision(2); 
        cout << "Cartesian coordinates are: (" << x << ", " << y << ")." << endl;
    }
};

int main() {
    ConvertPtoC p1;
    p1.input();
    p1.convert();
    p1.display();
    return 0;
}
