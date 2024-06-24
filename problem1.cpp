// Create a 'DISTANCE' class with :
// - feet and inches as data members
// - member function to input distance
// - member function to output distance
// - member function to add two distance objects
// Write a main function to create objects of DISTANCE class. Input two distances
// and
// output the sum.


#include <iostream>
using  namespace std; 
class DISTANCE {
private:
    int feet;
    int inches;

public:
    DISTANCE() : feet(0), inches(0) {}

    void inputDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        normalize();
    }

    void outputDistance() const {
        cout << feet << " feet " << inches << " inches\n";
    }

    DISTANCE addDistance(const DISTANCE& d) const {
        DISTANCE result;
        result.feet = feet + d.feet;
        result.inches = inches + d.inches;
        result.normalize();
        return result;
    }

private:
    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }
};

int main() {
    DISTANCE d1, d2, d3;

    cout << "Enter first distance:\n";
    d1.inputDistance();
    cout << "Enter second distance:\n";
    d2.inputDistance();

    d3 = d1.addDistance(d2);

    cout << "First distance: ";
    d1.outputDistance();
    cout << "Second distance: ";
    d2.outputDistance();
    cout << "Sum of distances: ";
    d3.outputDistance();

    return 0;
}
