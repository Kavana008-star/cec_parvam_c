#include<iostream>
#include<string>
using namespace std;
class rectangle
{
    private:
    double length;
    double breadth;
    public:
    rectangle(){
        length=0;
        breadth=0;
        cout<<"Default constructor called"<<endl;
    }
    rectangle(double side)
    {
        length=side;
        breadth=side;
        cout<<"square constructor called"<<endl;
    }
    rectangle(double l,double w)
    {
        length=l;
        breadth=w;
        cout<<"two parameter constructor called"<<endl;
    }
    rectangle(const rectangle &r)
    {
        length=r.length;
        breadth=r.breadth;
        cout<<"Copy constructor called"<<endl;
    }
    double area(){
        return length*breadth;
    
    }
};
int main()
{
    rectangle r1;
    cout<<"Area of r1: "<<r1.area()<<endl;
    rectangle r2(5);
    cout<<"Area of r2: "<<r2.area()<<endl;
    rectangle r3(4,6);
    cout<<"Area of r3: "<<r3.area()<<endl;
    rectangle r4=r3;
    cout<<"Area of r4: "<<r4.area()<<endl;
    return 0;
}