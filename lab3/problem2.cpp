#include <iostream>
#include <cmath>
#include <iomanip>  

using namespace std;


class polar {
private:
    double r, theta;

public:
    polar() : r(0), theta(0) {}
    polar(double R, double THETA) : r(R), theta(THETA) {}
    void input() {

        cout << "Enter the value of r and theta (in radian): " << endl;
        cin >> r >> theta;
    }
    double returntheta(){
        return theta;
    }
    double return_r(){
        return r;
    }
};
class cart {
private:
    double x, y;

public:
    cart(double x1,double y1) : x(x1),y(y1){};
        void display() {
        cout << fixed << setprecision(2); 

        cout << "Cartesian coordinates are: (" << x << ", " << y << ")." << endl;
    }
    cart (polar &c1) {
        double thetaRad = c1.returntheta(); 
        x = c1.return_r()* cos(thetaRad);
        y = c1.return_r()* sin(thetaRad);
    }
};



int main() {
    polar p1;
    p1.input();
    cart c1=p1; 
    c1.display();
    return 0;
}
