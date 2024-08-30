#include <iostream>
#include <cstring>
using namespace std;

class TIME_24
{
private:
    int hour, min, sec;

public:
    TIME_24(int h, int m, int s) : hour(h), min(m), sec(s) {}
    TIME_24() : hour(0), min(0), sec(0) {}
    void get_input()
    {
        cout << "Enter the time in 24-hour format (HH MM SS): ";
        cin >> hour >> min >> sec;
    }
    void display() const
    {
        cout << "Time in 24 hours: " << hour << ":" << min << ":" << sec << endl;
    }
    int get_hour() const { return hour; }
    int get_min() const { return min; }
    int get_sec() const { return sec; }
};

class TIME
{
private:
    int hour, min, sec;
    char time_AM_PM[3];

public:
    TIME() : hour(0), min(0), sec(0) { strcpy(time_AM_PM, "AM"); }
    TIME(const TIME_24 &t)
    {
        hour = t.get_hour();
        min = t.get_min();
        sec = t.get_sec();
        if (hour == 0)
        {
            hour = 12;
            strcpy(time_AM_PM, "AM");
        }
        else if (hour == 12)
        {
            strcpy(time_AM_PM, "PM");
        }
        else if (hour > 12)
        {
            hour -= 12;
            strcpy(time_AM_PM, "PM");
        }
        else
        {
            strcpy(time_AM_PM, "AM");
        }
    }
    void display() const
    {
        cout << "Time in 12 hours: " << hour << ":" << min << ":" << sec << " " << time_AM_PM << endl;
    }
};

int main()
{
    TIME_24 t1;
    t1.get_input();
    t1.display();

    TIME t2 = t1;
    t2.display();

    return 0;
}
