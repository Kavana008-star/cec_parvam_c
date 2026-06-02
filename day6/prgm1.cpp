#include<iostream>
#include<string>
using namespace std;
class calculator
{
    public:
    int add(int a,int b)
    {
        cout<<"int+int=";
        return a+b;
    }
    double add(double a,double b)
    {
        cout<<"double+double=";
        return a+b;
    }
    string add(string a,string b)
    {
        cout<<"string+string=";
        return a+b;
    }
    double add(int a,double b)
    {
        cout<<"int+double=";
        return a+b;
    }
    double add(double a,int b)
    {
        cout<<"double+int=";
        return a+b;
    }
    int add(int a,int b,int c)
    {
        cout<<"int+int+int=";
        return a+b+c;
    }
};
int main()
{
    calculator cal;
    cout<<cal.add(5,10)<<endl;      
    cout<<cal.add(5.5,10.5)<<endl;
    cout<<cal.add("Hello, ","World!")<<endl;
    cout<<cal.add(5,10.5)<<endl;
    cout<<cal.add(5.5,10)<<endl;
    cout<<cal.add(5,10,15)<<endl;
    return 0;
}
    