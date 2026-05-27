#include<iostream>
#include<string>
using namespace std;
class student
{
public:
    string name;
    int marks;
    student(){name="unknown"; marks=0;}
    student(string n, int m){name=n; marks=m;}
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Marks: "<<marks<<endl;
    }   
};
student batch[3]={
    student("Arjun",85),
    student("priya",90),
    student("rahul",78)
};
cout<<"Batch 1 (stack array):"<<endl;
for(int i=0;i<3;i++){
    batch[i].display();
    cout<<endl;
}
student* batch2=new student[3]{
    student("sneha",88),
    student("Vikram",76),
    student("Ananya",95)
};
cout<<"Batch 2 (heap array):"<<endl;
for(int i=0;i<3;i++){
    batch2[i].display();
    cout<<endl;
} 
delete[] batch2;
return 0;
