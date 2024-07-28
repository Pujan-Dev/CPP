#include <iostream>
#include <cstring>
using namespace std;
class Person {
protected:
      char name[30];
    int age;
    int id;

public:
    Person(char names[30], int ages, int ids){
        strcpy(name,names);
        age=ages;
        id =ids;


    }

    void displayPersonInfo() const {
         cout << "Name: " << name << "\nAge: " << age << "\nID: " << id <<  endl;
    }
};

class Employee : public Person {
protected:
      char designation;
    double basicSalary;
    int totalOvertimeHours;
    double hourlyRate;

public:
    Employee(const   char name[], int age, int id, const   char designation, double basicSalary, int totalOvertimeHours, double hourlyRate)
        : Person(name[], age, id), designation(designation), basicSalary(basicSalary), totalOvertimeHours(totalOvertimeHours), hourlyRate(hourlyRate) {}

    void displayEmployeeInfo() const {
        displayPersonInfo();
         cout << "Designation: " << designation 
                  << "\nBasic Salary: " << basicSalary 
                  << "\nTotal Overtime Hours: " << totalOvertimeHours 
                  << "\nHourly Rate: " << hourlyRate <<  endl;
    }
};

class ComputedSalary : public Employee {
public:
    ComputedSalary(const   char &name, int age, int id, const   char &designation, double basicSalary, int totalOvertimeHours, double hourlyRate)
        : Employee(name, age, id, designation, basicSalary, totalOvertimeHours, hourlyRate) {}

    double computeTotalSalary() const {
        return basicSalary + (totalOvertimeHours * hourlyRate);
    }

    void displayTotalSalary() const {
         cout << "Total Salary: " << computeTotalSalary() <<  endl;
    }
};

int main() {
    ComputedSalary employee("John Doe", 30, 12345, "Software Engineer", 5000.0, 10, 20.0);

     cout << "Employee Information:" <<  endl;
    employee.displayEmployeeInfo();
     cout << "Salary Information:" <<  endl;
    employee.displayTotalSalary();

    return 0;
}
