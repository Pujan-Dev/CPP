// Create a class called 'TIME' that has
// - three integer data members for hours, min and sec
// - constructor to initialize the object to zero
// - constructor to initialize the object to some constant value
// - overload +,- to add and subtract two TIME objects
// - overload > function to compare two time
// - member function to display time in HH:MM:SS format

#include <iostream>
using namespace std;

class TIME
{
private:
    int hours, min, sec;
    void normalize()
    {
        if (sec >= 60)
        {
            min += sec / 60;
            sec %= 60;
        }
        if (min >= 60)
        {
            hours += min / 60;
            min %= 60;
        }
        if (sec < 0)
        {
            min -= (abs(sec) / 60) + 1;
            sec = 60 - (abs(sec) % 60);
        }
        if (min < 0)
        {
            hours -= (abs(min) / 60) + 1;
            min = 60 - (abs(min) % 60);
        }
    }

public:
    // Constructor to initialize the object to zero
    TIME() : hours(0), min(0), sec(0) {}

    // Constructor to initialize the object to some constant value
    TIME(int hr, int mn, int se) : hours(hr), min(mn), sec(se)
    {
        normalize();
    }
    TIME operator+(TIME &t2)
    {
        TIME t3;
        t3.hours = (t2.hours + hours);
        t3.min = t2.min + min;
        t3.sec = t2.sec + sec;
        t3.normalize();
        return t3;
    }
    TIME operator-(TIME &t2)
    {
        TIME t3;
        t3.hours = (t2.hours - hours);
        t3.min = t2.min - min;
        t3.sec = t2.sec - sec;
        t3.normalize();
        return t3;
    }
    bool operator>(TIME &t2)
    {
        if (hours > t2.hours)
            return true;
        if (hours == t2.hours && min > t2.min)
            return true;
        if (hours == t2.hours && min == t2.min && sec > t2.sec)
            return true;
        return false;
    }
    void display()
    {
        cout << hours << ":" << min << ":" << sec << "" << endl;
    }
};

int main()
{
    TIME t1(1, 2, 3), t2(5, 20, 00);
    TIME t3;
    t3 = t1 + t2;
    cout << "T1+T2=";
    t3.display();
    t3 = t1 - t2;
    cout << "T1-T2=";
    t3.display();
    if (t1 > t2)
    {
        cout << "T1 is greater than T2" << endl;
    }
    else
    {
        cout << "T1 is not greater than T2" << endl;
    }
}