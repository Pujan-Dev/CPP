#include <iostream>
#include <cstring>
using namespace std;

class student
{
private:
    char name[255];
    int rn; // Roll number

public:
    student()
    {
        strcpy(name, "Unknown");
        rn = 0;
    }

    student(const char *names, int roll_number)
    {
        strcpy(name, names);
        rn = roll_number;
    }
    void getdata()
    {
        cout << "Enter student's name: ";
        cin.ignore();
        cin.getline(name, 255);
        cout << "Enter roll number: ";
        cin >> rn;
    }

    void putdata() const
    {
        cout << "Name: " << name << ", Roll Number: " << rn << endl;
    }

    int get_roll_number() const
    {
        return rn;
    }

    const char *get_name() const
    {
        return name;
    }
};

class InternalExam : public student
{
private:
    int m[7];

public:
    void getdata()
    {
        student::getdata();
        cout << "Enter internal exam marks for 7 subjects: ";
        for (int i = 0; i < 7; ++i)
        {
            cin >> m[i];
        }
    }

    void putdata() const
    {
        student::putdata();
        cout << "Internal Exam Marks: ";
        for (int i = 0; i < 7; ++i)
        {
            cout << m[i] << " ";
        }
        cout << endl;
    }

    int getmark(int index) const
    {
        return m[index];
    }
};

class FinalExam : public student
{
private:
    int m[7];

public:
    void getdata()
    {
        student::getdata();
        cout << "Enter final exam marks for 7 subjects: ";
        for (int i = 0; i < 7; ++i)
        {
            cin >> m[i];
        }
    }

    void putdata() const
    {
        student::putdata();
        cout << "Final Exam Marks: ";
        for (int i = 0; i < 7; ++i)
        {
            cout << m[i] << " ";
        }
        cout << endl;
    }

    int getmark(int index) const
    {
        return m[index];
    }
};

class avgmarks : public InternalExam, public FinalExam
{
private:
    float Avgmarks;

public:
    void calculate_avg()
    {
        int total = 0;
        for (int i = 0; i < 7; ++i)
        {
            total += InternalExam::getmark(i) + FinalExam::getmark(i);
        }
        Avgmarks = total / 14.0; // Total marks for 14 exams (internal and final)
    }

    void putdata() const
    {
        InternalExam::putdata();
        FinalExam::putdata();
        cout << "Average Marks: " << Avgmarks << endl;
    }
};

int main()
{
    avgmarks student_avg;
    cout << "Enter data for Internal Exam:\n";
    student_avg.InternalExam::getdata();
    cout << "\nEnter data for Final Exam:\n";
    student_avg.FinalExam::getdata();

    student_avg.calculate_avg();
    cout << "\nDisplaying data:\n";
    student_avg.putdata();

    return 0;
}
