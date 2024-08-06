#include <iostream>
#include <cstring>
using namespace std;

class TIME
{
private:
    int hour, min, sec;
    int oldhours;
    char time_AM_PM[3];

public:
    TIME(int h, int m, int s) : hour(h), min(m), sec(s) {}
    TIME() : hour(0), min(0), sec(0) {}
    void get_input()
    {
        cout << "Enter the time in hr, min, sec format(HH:MIN:SEC): ";
        cin >> hour >> min >> sec;
    }
    void convert()
    {
        oldhours = hour;
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
    void display()
    {
        cout << "Time in 24 hours: " << oldhours << ":" << min << ":" << sec << "\n"
             << "Time in 12 hours: " << hour << ":" << min << ":" << sec << " " << time_AM_PM << endl;
    }
    int return_hr()
    {
        return hour;
    }
    int return_min()
    {
        return min;
    }
    int return_sec()
    {
        return sec;
    }
    char* get_AM_PM()
    {
        return time_AM_PM;
    }
};

class time_convert
{
private:
    int hour, min, sec;
    char time_AM_PM[3];

public:
    time_convert(int h, int m, int s, const char* am_pm) : hour(h), min(m), sec(s)
    {
        strcpy(time_AM_PM, am_pm);
    }
    time_convert() : hour(0), min(0), sec(0)
    {
        strcpy(time_AM_PM, "AM");
    }
    time_convert(TIME &t)
    {
        hour = t.return_hr();
        min = t.return_min();
        sec = t.return_sec();
        strcpy(time_AM_PM, t.get_AM_PM());
    }
    void display()
    {
        cout << "Time in 12 hours: " << hour << ":" << min << ":" << sec << " " << time_AM_PM << endl;
    }
};

int main()
{
    TIME t1;
    t1.get_input();
    t1.convert();
    time_convert t2(t1);
    t2.display();
    return 0;
}
