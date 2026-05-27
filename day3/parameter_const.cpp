#include<iostream>
#include<string>
using namespace std;
class student
{
    public:
    string name;
    int age;
    double cgpa;
    student(string n,int a,double c)
    {
        name=n;
        age=a;
        cgpa=c;
        cout<<"Parameterized constructor called"<<name<<endl;
}
void display()
{
    cout<<"|age: "<<age<<"|cgpa: "<<cgpa<<"|"<<endl;
}
};
int main()
{
    student s1("Arjun",20,3.5);
    student s2("priya",22,3.8);
    s1.display();
    s2.display();
    return 0;
}