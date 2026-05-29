#include<iostream>
using namespace std;
int main()
{
    int x=10;
    int* ptr;
    ptr=&x;
    cout<<"Value of x: "<<x<<endl;
    cout<<"Address of x: "<<&x<<endl;
    cout<<"Value at address stored in ptr: "<<ptr<<endl;
    cout<<"Value pointed to by ptr: "<<*ptr<<endl;
    *ptr=20;
    cout<<"x after *ptr=20: "<<x<<endl;
    int* nullptr= nullptr;
    return 0;
}
