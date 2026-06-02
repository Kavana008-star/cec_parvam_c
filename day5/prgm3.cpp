#include <iostream>
#include <string>
using namespace std;

// Base Class
class {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a), salary(0) {}

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
        cout<<"salary: "<<salary<<endl;
    }
};

// Single Inheritance
class Student : public Person {
protected:
    int rollNo;
public:
    HR(string n, int a, int r)                 
        : Person(n, a), rollNo(r) {}

    void display() {
        Person::display();
        cout << "Roll No: " << rollNo << endl;
    }
};

// Multilevel Inheritance
class GraduateStudent : public Student {
private:
    string thesisTopic;

public:
    GraduateStudent(string n, int a, int r, string t)
        : Student(n, a, r), thesisTopic(t) {}

    void display() {
        Student::display();
        cout << "Thesis Topic: " << thesisTopic << endl;
    }
};

// Hierarchical Inheritance
class Teacher : public Person {
protected:
    double salary;

public:
    Teacher(string n, int a, double s)
        : Person(n, a), salary(s) {}

    void display() {
        Person::display();
        cout << "Salary: $" << salary << endl;
    }
};

// Multiple Inheritance
class TeachingAssistant : public Student, public Teacher {
public:
    TeachingAssistant(string n, int a, int r, double s)
        : Student(n, a, r), Teacher(n, a, s) {}

    void display() {
        cout << "Teaching Assistant Details:" << endl;

        // Access through Student branch
        cout << "Name: " << Student::name << endl;
        cout << "Age: " << Student::age << " years" << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    cout << "---- Single Inheritance Example ----" << endl;
    Student s1("Alice", 20, 101);
    s1.display();

    cout << "\n---- Multilevel Inheritance Example ----" << endl;
    GraduateStudent gs1("Bob", 25, 102, "Artificial Intelligence");
    gs1.display();

    cout << "\n---- Hierarchical Inheritance Example ----" << endl;
    Teacher t1("David", 40, 50000);
    t1.display();

    cout << "\n---- Multiple Inheritance Example ----" << endl;