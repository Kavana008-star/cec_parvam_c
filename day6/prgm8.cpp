#include <iostream>
using namespace std;

class Base {
    public:
        void nonVirtual() { cout << "Base::nonVirtual" << endl; }
        virtual void virtualFunc() { cout << "Base::virtualFunc" << endl; }
        virtual ~Base() {}
};

class Derived : public Base {
    public:
        void nonVirtual() { cout << "Derived::nonVirtual" << endl; }
        void virtualFunc() override { cout << "Derived::virtualFunc" << endl; }
};

int main() {
    Base* ptr = new Derived();
    
    cout << "Called via Base* pointing to Derived object:" << endl;
    cout << "Non-virtual: "; ptr->nonVirtual();   // Base::nonVirtual (static binding)
    cout << "Virtual    : "; ptr->virtualFunc();   // Derived::virtualFunc (dynamic binding)
    
    cout << "\nCalled via reference:" << endl;
    Derived d;
    Base& ref = d;
    ref.nonVirtual();     // Base::nonVirtual (static binding)
    ref.virtualFunc();    // Derived::virtualFunc (dynamic binding)
    
    delete ptr;
    return 0;
}