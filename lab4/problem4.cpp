#include <iostream>
using namespace std;

// 4. class Date
class Date
{
    int day, month, year;

public:
    Date(int initYear, int initMonth, int initDay)
    {
        day = initDay;
        month = initMonth;
        year = initYear;

        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        {
            cout << "Invalid date" << endl;
            exit(1);
        }
    }

    ~Date()
    {
        cout << "Date object destroyed" << endl;
    }
    void display()
    {
        cout << "Date: " << year << "/" << month << "/" << day << endl;
    }
    // Date get();
    void set()
    {
        cout << "Enter date (yyyy mm dd): ";
        cin >> year >> month >> day;

        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        {
            cout << "Invalid date" << endl;
            exit(1);
        }
    }
};

// class Time
class Time
{
    int hour;
    int minute;
    int second;

public:
    Time(int initHour, int initMinute, int initSecond)
    {
        hour = initHour;
        minute = initMinute;
        second = initSecond;

        if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
        {
            cout << "Invalid time" << endl;
            exit(1);
        }
    }
    ~Time()
    {
        cout << "Time object destroyed" << endl;
    }
    void display()
    {
        cout << "Time: " << hour << ":" << minute << ":" << second << endl;
    }
    // Time get();
    void set()
    {
        cout << "Enter time (hh mm ss) 24 hr format: ";
        cin >> hour >> minute >> second;
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
        {
            cout << "Invalid time" << endl;
            exit(1);
        }
    }
};

// class DateAndTime : public Date, public Time
class DateAndTime : public Date, public Time
{
public:
    DateAndTime(int initYear, int initMonth, int initDay, int initHour, int initMinute, int initSecond) : Date(initYear, initMonth, initDay), Time(initHour, initMinute, initSecond)
    {
    }
    void display()
    {
        Date::display();
        Time::display();
    }
};

int main()
{
    DateAndTime Watch(2023, 7, 29, 14, 45, 30);
    Watch.display();
    Watch.Date::set();
    Watch.Time::set();
    Watch.display();
    return 0;
}
