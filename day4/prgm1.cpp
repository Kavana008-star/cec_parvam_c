#include<iostream>
class student{
    private:
    string name;
    int age;
    double cgpa;
    public:
    string getname()const{return name;}
    int getage()const{return age;}
    double getcgpa()const{return cgpa;}
    void setname(string n){name=n;}
    void setage(int a){
        if(a>0 && a<150)
        age=a;
        else{
        cout<<"invalid age"<<endl;
    }
}
    void setcgpa(double c){
        if(c>=0 && c<=10)
        cgpa=c;
        else
        cout<<"invalid CGPA! must be between 0 and 10.0"<<endl;
    }

    int main()
    {
        student s1;
        s1.setname("Alice");
        s1.setage(20);
        s1.setcgpa(8.5);
        cout<<"Name: "<<s1.getname()<<endl;
        cout<<"Age: "<<s1.getage()<<endl;
        cout<<"CGPA: "<<s1.getcgpa()<<endl;
        return 0;
    }
};