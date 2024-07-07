/*
A parking garage charges a $2.00 minimum fee to park for up to three
hours. The garage charges an additional $0.50 per hour for each hour or
part thereof in excess of three hours. People who park their cars for
longer than 24 hours will pay $8.00 per day. Write a program that
calculates and prints the parking charges. The inputs to your program
are the date and time when a car enters the parking garage, and the date
and time when the same car leaves the parking garage. Keep track of
number of cars in the garage overloading ++ and -- operators. 

*/

#include <iostream>
#include <cmath>
using namespace std;

class DateTime {
private:
    int days, hours, minutes;

public:
    DateTime(int d = 0, int h = 0, int m = 0) : days(d), hours(h), minutes(m) {}

    int getTotalHours() const {
        return days * 24 + hours + (minutes > 0 ? 1 : 0); // round up to next hour if there are minutes
    }

    int getHours() const {
        return hours;
    }

    void setHours(int h) {
        hours = h;
    }

    void operator++() {
        hours++;
        if (hours >= 24) {
            days++;
            hours = 0;
        }
    }

    void operator--() {
        if (hours > 0) {
            hours--;
        } else {
            if (days > 0) {
                days--;
                hours = 23;
            }
        }
    }
};

class ParkingGarage {
private:
    double totalEarnings;
    int carCount;

public:
    ParkingGarage() : totalEarnings(0), carCount(0) {}

    void enter(DateTime enterTime) {
        ++carCount;
    }

    void leave(DateTime enterTime, DateTime leaveTime) {
        --carCount;

        int duration = leaveTime.getTotalHours() - enterTime.getTotalHours();

        double charge = 0;
        if (duration <= 3) {
            charge = 2.0;
        } else if (duration <= 24) {
            charge = 2.0 + 0.5 * (duration - 3);
        } else {
            charge = 8.0 * ceil(duration / 24.0); // charge per full day
        }

        totalEarnings += charge;

        cout << "Parking charge: $" << charge << endl;
    }

    void displayEarnings() const {
        cout << "Total earnings: $" << totalEarnings << endl;
    }

    int getCarCount() const {
        return carCount;
    }
};

int main() {
    ParkingGarage garage;

    DateTime enterTime(0, 10, 15); // Example: car enters at day 0, 10:15 AM
    DateTime leaveTime(1, 13, 30); // Example: car leaves at day 1, 1:30 PM
    DateTime enterTime1(0, 10, 15); // Example: car enters at day 0, 10:15 AM
    DateTime leaveTime1(1, 13, 30); // Example: car leaves at day 1, 1:30 PM

    garage.enter(enterTime);
    garage.leave(enterTime, leaveTime);
    garage.enter(enterTime1);
    garage.leave(enterTime1, leaveTime1);

    garage.displayEarnings();

    return 0;
}
