//  Overload >> and << operators to input and display time.
#include <iostream>

using namespace std;
class TIME{
private:
    int hr, min, sec;

public:
    TIME(int h, int m, int s)
    {
        hr = h;
        min = m;
        sec = s;
    }
    TIME() : hr(0), min(0), sec(0) {}
    friend ostream &operator<<(ostream &out, TIME &t)
    {
        out << t.hr << ":" << t.min << ":" << t.sec;
        return out;
    }
    friend istream &operator>>(istream &in, TIME &t)
    {
        in >> t.hr >> t.min >> t.sec;
        return in;
    }
};

int main(){
    TIME t1;
    cout << "Enter time (hours minutes seconds): ";
    cin >> t1;
    cout << "The time is: " << t1 << endl;
    return 0;
}