// Program: Given that an EMPLOYEE class contains following members:
// data members: Employee number, Employee name, Basic, DA, IT, Net Salary
// and print data members. Write a C++ program to read the data of N employee
// and compute Net salary of each employee (DA=52% of Basic and Income Tax
// (IT) =30% of the gross salary) .
#include <iostream>
#include <cstring>

using namespace std;

class EMPLOYEE {
private:
    int empNumber;
    char empName[100];
    char designation[100];
    double basic;
    double da;
    double it;
    double netSalary;

    static int managerCount;
    static int engineerCount;
    static int technicianCount;

public:
    EMPLOYEE() {
        empNumber = 0;
        empName[0] = '\0';
        designation[0] = '\0';
        basic = 0.0;
        da = 0.0;
        it = 0.0;
        netSalary = 0.0;
    }

    void readData() {
        cout << "Enter Employee Number: ";
        cin >> empNumber;
        cout << "Enter Employee Name: ";
        cin >> empName;
        cin.ignore();  // Ignore the newline character left in the buffer
        cout << "Enter Designation (Manager/Engineer/Technician): ";
        cin.getline(designation, 100);
        cout << "Enter Basic Salary: ";
        cin >> basic;

        computeSalary();
        updateDesignationCount();
    }

    void computeSalary() {
        da = 0.52 * basic;
        double grossSalary = basic + da;
        it = 0.30 * grossSalary;
        netSalary = grossSalary - it;
    }

    void printData() const {
        cout << "Employee Number: " << empNumber << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Designation: " << designation << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "Dearness Allowance (DA): " << da << endl;
        cout << "Income Tax (IT): " << it << endl;
        cout << "Net Salary: " << netSalary << endl;
    }

    static void printDesignationCounts() {
        cout << "\nDesignation Counts:\n";
        cout << "Managers: " << managerCount << endl;
        cout << "Engineers: " << engineerCount << endl;
        cout << "Technicians: " << technicianCount << endl;
    }

private:
    bool compareStrings(const char* str1, const char* str2) const {
        return strcmp(str1, str2) == 0;
    }

    void updateDesignationCount() {
        if (compareStrings(designation, "Manager")) {
            managerCount++;
        } else if (compareStrings(designation, "Engineer")) {
            engineerCount++;
        } else if (compareStrings(designation, "Technician")) {
            technicianCount++;
        }
    }
};

int EMPLOYEE::managerCount = 0;
int EMPLOYEE::engineerCount = 0;
int EMPLOYEE::technicianCount = 0;

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    EMPLOYEE* employees = new EMPLOYEE[n];

    for(int i = 0; i < n; ++i) {
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        employees[i].readData();
    }

    cout << "\nEmployee Details:\n";
    for(int i = 0; i < n; ++i) {
        cout << "\nDetails of employee " << i + 1 << ":\n";
        employees[i].printData();
    }

    EMPLOYEE::printDesignationCounts();

    delete[] employees;
    return 0;
}
