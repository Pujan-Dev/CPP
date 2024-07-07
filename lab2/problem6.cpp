/*
Modify above class to work with compile time memory allocation i.e. with char [].
*/


#include <iostream>
#include <cstring>

using namespace std;
#define SIZE 100
class String
{
private:
    char text[SIZE];
    int len;

public:
    String(const char* txt = "")
    {
        len = strlen(txt);
        strcpy(text, txt);
    }
    String(char txt[])
    {
        len = strlen(txt);
        strcpy(text, txt);
    }

    void operator=(String& s) // s1=s2
    {
        strcpy(text,s.text);
    }
    String operator+(String& s)
    {
        char newText[SIZE];
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
    String s2("WORLD");
    String s3 = s1 + s2;
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