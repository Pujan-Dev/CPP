#include <iostream>

using namespace std;
class base
{
private:
    int first;
    bool isalive;
public:
    virtual void test(){
        cout<<"Hello";
    }
};



class derive: public base
{
private:
    int hello;
    /* data */
public:
    void test(){
        cout<<"Hello1";
    }
};


int main(){
    base *D1;
    D1 = new derive;
    D1->test();
}