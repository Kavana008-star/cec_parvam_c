#include <iostream.h>
#include <string>
using namespace std;
class student 
{
    public:
    string name;
    int marks;
    string email;
    student() {name = "unknown"; marks=0; email = "unknown";}
    student(string n,int m,string e) {name=n; marks=m; email=e;}
    void display()

    {
  
      cout<<name<<":"<<marks<<":"<<email<<endl;

    }
};
int main()
{
    student batch1[3]={
        student("arjun",85,"arjun@example.com");
        student("priya",92,"priya@example.com");
        student("rahul",78,"rahul@example.com");


    };
    cout<<"batch1 (stack array):"<<endl;
    for(int i=0; i<3; i++)
    {
        batch1[i].display();
        cout<<endl;

    };
    student* batch2=new student[3]{
        student("sita",88,"sita@example.com");
        student("gita",91,"gita@example.com");
        student("laxman",80,"laxman@example.com");

    };
    cout<<"\n batch2 (heap array):"<<endl;
    for(int i=0; i<3; i++)  
    {
        batch2[i].display();
    }   
   
    delete[] batch2;
    return 0;  
}