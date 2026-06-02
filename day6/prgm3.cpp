#include<iostream>
#include<string>
using namespace std;

class StudentTeacher
{
public:

    string details(string fname, string lname)
    {
        cout<<"Student Name: ";
        return fname + " " + lname;
    }

    int details(int attendance)
    {
        cout<<"Attendance: ";
        return attendance;
    }

    double details(double marks)
    {
        cout<<"Marks: ";
        return marks;
    }

    double details(double m1, double m2, double m3)
    {
        cout<<"Total Marks: ";
        return m1 + m2 + m3;
    }

    string details(string tname)
    {
        cout<<"Teacher Name: ";
        return tname;
    }

    string details(string tname, string subject)
    {
        cout<<"Teacher & Subject: ";
        return tname + " - " + subject;
    }
};

int main()
{
    StudentTeacher st;

    cout<<st.details("Kavana","Yogesh")<<endl;
    cout<<st.details(95)<<"%"<<endl;
    cout<<st.details(88.5)<<endl;
    cout<<st.details(85.0,90.0,92.0)<<endl;

    cout<<st.details("Ramesh")<<endl;
    cout<<st.details("Ramesh","Computer Science")<<endl;

    return 0;
}