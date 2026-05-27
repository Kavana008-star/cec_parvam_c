#include<iostream>
#include<cstring>
using namespace std;
class student
{
    public:
    char name[20];
    int age;
    student(const char* n,int a)
    {
        age=a;
        strcpy(name,n);
    }
student(const student &s)
{
     age=s.age;
    name=new char[strlen(s.name)+1];
    strcpy(name,s.name);
    cout<<"Copy constructor called"<<endl;
}
void display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
}
~student()
{
    delete[] name;
}
};
int main()
{
    student s1("Arjun",20);
    student s2=s1;
    s1.display();
    s2.display();
    return 0;
}