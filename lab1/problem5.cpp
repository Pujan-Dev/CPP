#include <iostream>
#include <vector>
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

public:
    // Constructor
    Employee(int number, const string &name, char desig)
        : empNumber(number), empName(name), designation(desig)
    {
        categorizeEmployee();
    }

    static void displayEmployeeCounts()
    {
        cout << "Employee Counts by Designation:" << endl;
        cout << "Managers: " << managerCount << endl;
        cout << "Engineers: " << engineerCount << endl;
        cout << "Others: " << otherCount << endl;
        cout << "Total no of employee: "<< managerCount+engineerCount+otherCount<<endl;
    }

private:
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
};

int Employee::managerCount = 0;
int Employee::engineerCount = 0;
int Employee::otherCount = 0;

int main()
{
    vector<Employee> employees;
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

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

        employees.emplace_back(empNumber, empName, designation);
    }

    Employee::displayEmployeeCounts();

    return 0;
}
