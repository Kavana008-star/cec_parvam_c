#include<iostream>
using namespace std;
int main()
{
    int* p = new int; 
    *p = 10;
    cout << "Value: " << *p << endl;
    delete p;
    p = nullptr; 
    int* q = new int(100);
    cout<<"value: "<<*q<<endl;
    delete q;  
    return 0;
}