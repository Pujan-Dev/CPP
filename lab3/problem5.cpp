#include <iostream>
#include <cstring>
using namespace std;

void toUpperCase(char str[])
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        str[i] = toupper(str[i]);
    }
}

class TIME
{
private:
    int hour, min, sec;
    char time_AM_PM[3]; // increased size to 3 to hold "AM"/"PM" and the null terminator

public:
    TIME(int h, int m, int s, const char *am_pm) : hour(h), min(m), sec(s)
    {
        strcpy(time_AM_PM, am_pm);
    }
    TIME() : hour(0), min(0), sec(0)
    {
        strcpy(time_AM_PM, "AM");
    }
    void get_input()
    {
        cout << "Enter the time in hr, min, sec, daytime (AM/PM): ";
        cin >> hour >> min >> sec >> time_AM_PM;
        toUpperCase(time_AM_PM); // ensure the AM/PM is in uppercase
    }
    int get_hour() const { return hour; }
    int get_min() const { return min; }
    int get_sec() const { return sec; }
    const char *get_AM_PM() const { return time_AM_PM; }
    void display() const
    {
        cout << "Time in 12 hours: " << hour << ":" << min << ":" << sec << " " << time_AM_PM << endl;
    }
};

class TIME_24
{
private:
    int hour, min, sec;

public:
    TIME_24(int h, int m, int s) : hour(h), min(m), sec(s) {}
    TIME_24() : hour(0), min(0), sec(0) {}
    TIME_24(const TIME &t)
    {
        hour = t.get_hour();
        min = t.get_min();
        sec = t.get_sec();
        if (strcmp(t.get_AM_PM(), "AM") == 0 && hour == 12)
        {
            hour = 0; // 12 AM is 00:xx in 24-hour format
        }
        else if (strcmp(t.get_AM_PM(), "PM") == 0 && hour != 12)
        {
            hour += 12;
        }
    }
    void display() const
    {
        cout << "Time in 24 hours: " << hour << ":" << min << ":" << sec << endl;
    }
};

int main()
{
    TIME t1;
    t1.get_input();
    t1.display();

    TIME_24 t2 = t1;
    t2.display();

    return 0;
}
