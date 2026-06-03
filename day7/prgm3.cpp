#include<iostream>
#include<string>
using namespace std;
class student {
public:
string name;
int age;
student(string n,int a) : name(n), age(a) {}
void display(){
    cout<<"(Name: "<<name<<", Age: "<<age<<")"<<endl;
}
};
int main()
{
student*s1=new student("Alice",20);
cout<<"names:"<<s1->name<<endl;
cout<<"age:"<<s1->age<<endl;
s1->display();
(*s1).display();
delete s1;
return 0;
}