/*Create a 'STRING' class which char* and length as data member and
overloads ‘+’ ,’=’ and ‘ = = ‘ to perform respective operations. Use
constructor and destructor whenever suitable.*/

#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char* text;
    int len;

public:
    String(const char* txt = "")
    {
        len = strlen(txt);
        text = new char[len + 1];
        strcpy(text, txt);
    }
    String(char txt[])
    {
        len = strlen(txt);
        text = new char[len + 1];
        strcpy(text, txt);
    }
    ~String()
    {
        delete[] text;
    }
    void operator=(String& s) // s1=s2
    {
        strcpy(text,s.text); //text = s.text
    }
    String operator+(String& s)
    {
        char* newText = new char[len + s.len + 1];
        strcpy(newText, text);
        strcat(newText, s.text);
        String newString(newText);
        
        return newString;
    }
    bool operator==(String& s){
        return(strcmp(text,s.text)==0);
    }
    void display(){
        cout<<text<<endl;
    }

    
};

int main()
{
    String s1("Hello");
    String s2("Hello");
    String s3 = s1 + s2; // s3(s1)
    cout << "Concatenated String: " ;
    s3.display();

    s3 = s1;
    cout << "Assigned String: ";
    s3.display() ;

    if (s1 == s2)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are not equal" << endl;

    return 0;
}