#include <iostream>
using namespace std;

class BaseWithoutVirtual {
    public:
        ~BaseWithoutVirtual() { cout << "Base WITHOUT virtual destructor" << endl; }
};

class BaseWithVirtual {
    public:
        virtual ~BaseWithVirtual() { cout << "Base WITH virtual destructor" << endl; }
};

class DerivedA : public BaseWithoutVirtual {
    public:
        ~DerivedA() { cout << "DerivedA destructor" << endl; }
};

class DerivedB : public BaseWithVirtual {
    public:
        ~DerivedB() { cout << "DerivedB destructor" << endl; }
};

int main() {
    cout << "=== Without virtual destructor (BUG!) ===" << endl;
    BaseWithoutVirtual* badPtr = new DerivedA();
    delete badPtr;  // Only calls Base destructor! Memory leak!
    
    cout << "\n=== With virtual destructor (CORRECT) ===" << endl;
    BaseWithVirtual* goodPtr = new DerivedB();
    delete goodPtr;  // Calls DerivedB destructor, then Base destructor
    
    return 0;
}