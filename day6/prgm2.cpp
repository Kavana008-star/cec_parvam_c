#include<iostream>
using namespace std;
class demo{
    public:
    void show(int a){cout<<"one int="<<a<<endl;}
    void show(int a ,int b){cout<<"two int="<<a<<" "<<b<<endl;}
    void display(int a,int b=0){cout<<"display="<<a<<","<<(b ? to_string(b) : "default")<<endl;}
};
int main()
{
    demo d;
    d.show(5);          
    d.show(5,10);       
    d.display(5);      
    d.display(5,10);   
    return 0;
}