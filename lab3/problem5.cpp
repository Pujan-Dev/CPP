// Program to convert time (hour, minute and second) in 12-hr format to 24-hr format
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
    int oldhours;
    char time_AM_PM[2];

public:
    TIME(int h, int m, int s) : hour(h), min(m), sec(s) {}
    TIME() : hour(0), min(0), sec(0) {}
    void get_input()
    {
        cout << "Enter the time in hr, min, sec , daytime (AM/ PM)" << endl;
        cin >> hour >> min >> sec >> time_AM_PM;
    }
    void convert() // 14-2pm
    {
        oldhours = hour;
        toUpperCase(time_AM_PM);
        if (hour >= 12 )
        {
        }

        else if (hour < 12 && strcmp(time_AM_PM, "PM"))
        {
        }
        else
        {
            hour += 12;
        }
    }
    void display()
    {
        cout << "Time in 12 hours " << oldhours << ":" << min << ":" << sec << " " << time_AM_PM << endl
             << "Time in 24 hours: " << hour << ":" << min << ":" << sec << "\n";
    }
};

int main()
{
    TIME t1;
    t1.get_input();
    t1.convert();
    t1.display();
    return 0;
}