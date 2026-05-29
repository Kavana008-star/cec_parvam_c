#include<iostream>
#include<string>
using namespace std;
class employee{
    private:
    string name;
    int id;
    double salary;
    string department;
    public:
    employee(int i,string n,double s,string d){
        id=i;
        name=n;
        salary=s;
        department=d;
    }
    int getid()const{return id;}
    string getname()const{return name;}     
    double getsalary()const{return salary;}
    string getdepartment()const{return department;}
    void setname(string& n)
    {
        if(n.length()>=2)
        {
            name=n;
        }
        else
        {
            cout<<"invalid name! must be at least 2 characters long."<<endl;
        }
    }
    void setsalary(double s)
    {
        if(s>=0)
        {
            salary=s;
        }
        else
        {
            cout<<"salary cannot be negative!"<<endl;
            salary=0;
        }
    }
    void setdepartment(const string& d)
    {
        department=d;
    }
    void giveraise(double percentage)
    {
        if (percentage>0)
        {
            salary+=salary*(percentage/100);
        cout<<name<<"received a"<<percentage<<"% raise. New salary: "<<salary<<endl;
        }
    }
    void display()const{
        cout<<"ID: "<<id<<"|"<<name<<"|$"<<salary<<"|"<<department<<endl;
    }
};
int main()
{
    employee emp(101,"John Doe",50000,"Engineering");
    emp.display();
    emp.giveraise(10);
    emp.setsalary(-100);
    cout<<"\nfinal employee details:"<<endl;
    cout<<"name: "<<emp.getname()<<endl;
    cout<<"salary: "<<emp.getsalary()<<endl;
    return 0;
}