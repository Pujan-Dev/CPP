// Program to convert time (hour, minute and second) in 24-hr format to 12-hr format
#include <iostream>
#include <cstring>
using namespace std;

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
        cout << "Enter the time in hr, min, sec format(HH:MIN:SEC)"<<endl;
        cin >> hour >> min >> sec;
    }
    void convert() //14-2pm
    {oldhours=hour;
        if (hour >= 12)
        {
            strcpy(time_AM_PM, "PM");
            hour-=12;
        }
        if (hour < 12)
        {
            strcpy(time_AM_PM, "AM");
        }
    }
    void display(){
        cout<<"Time in 24 hours: "<<oldhours<<":"<<min<<":"<<sec<<"\n"<<"Time in 12 hours "<<hour<<":"<<min<<":"<<sec<<" "<<time_AM_PM<<endl;
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