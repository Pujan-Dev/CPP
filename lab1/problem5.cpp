#include <iostream>
using namespace std;

class Employee
{
private:
    int empNumber;
    string empName;
    char designation;
    static int managerCount;
    static int engineerCount;
    static int otherCount;
    void categorizeEmployee()
    {
        if (designation == 'M')
        {
            managerCount++;
        }
        else if (designation == 'E')
        {
            engineerCount++;
        }
        else
        {
            otherCount++;
        }
    }

public:
    // Constructor
    Employee() {}
    Employee(int number, const string &name, char desig)
        : empNumber(number), empName(name), designation(desig)
    {
        categorizeEmployee();
    }

    // Static function to display employee counts
    static void displayEmployeeCounts()
    {
        cout << "Employee Counts by Designation:" << endl;
        cout << "Managers: " << managerCount << endl;
        cout << "Engineers: " << engineerCount << endl;
        cout << "Others: " << otherCount << endl;
        cout << "Total number of employees: " << managerCount + engineerCount + otherCount << endl;
    }
};

int Employee::managerCount = 0;
int Employee::engineerCount = 0;
int Employee::otherCount = 0;

int main()
{
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    Employee* employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; ++i)
    {
        int empNumber;
        string empName;
        char designation;

        cout << "Enter details for employee " << (i + 1) << ":" << endl;
        cout << "Employee Number: ";
        cin >> empNumber;
        cout << "Employee Name: ";
        cin.ignore(); // Ignore the newline character left in the buffer
        getline(cin, empName);
        cout << "Designation (M for Manager, E for Engineer, O for Other): ";
        cin >> designation;

        employees[i] = Employee(empNumber, empName, designation);
    }

    Employee::displayEmployeeCounts();

    delete[] employees; // Free dynamically allocated memory
    return 0;
}
