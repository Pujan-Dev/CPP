#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char name[255];
    int age, id;

public:
    Person(const char initName[] = "", int initAge = 0, int initID = 0) {
        strcpy(name, initName);
        age = initAge;
        id = initID;
    }

    void input() {
        cout << "Enter name, age and ID: ";
        cin.getline(name, 255);
        cin >> age >> id;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};

class Employee : public Person {
    char designation[255];

protected:
    float basicSalary, totalOvertime, hourlyRate;

public:
    Employee(const char initName[] = "", int initAge = 0, int initID = 0, const char initDesignation[] = "", float initBasicSalary = 0, float initTotalOvertime = 0, float initHourlyRate = 0) 
    : Person(initName, initAge, initID) {
        strcpy(designation, initDesignation);
        basicSalary = initBasicSalary;
        totalOvertime = initTotalOvertime;
        hourlyRate = initHourlyRate;
    }

    void input() {
        Person::input();
        cout << "Enter designation, basic salary, total overtime and hourly rate: ";
        cin.ignore();  // Clear the input buffer
        cin.getline(designation, 255);
        cin >> basicSalary >> totalOvertime >> hourlyRate;
    }

    void display() const {
        Person::display();
        cout << "Designation: " << designation << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Total Overtime: " << totalOvertime << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
    }
};

class ComputedSalary : public Employee {
     float totalSalary=0.0;

public:
    ComputedSalary(const char initName[] = "", int initAge = 0, int initID = 0, const char initDesignation[] = "", float initBasicSalary = 0, float initTotalOvertime = 0, float initHourlyRate = 0) 
    : Employee(initName, initAge, initID, initDesignation, initBasicSalary, initTotalOvertime, initHourlyRate) {}

    void display(){
        totalSalary = basicSalary + (totalOvertime * hourlyRate);
        Employee::display();
        cout << "Total Salary: " << totalSalary << endl;
    }
};

int main() {
    ComputedSalary employee;
    employee.input();
    employee.display();

    return 0;
}
