#include<iostream>
using namespace std;
class complex{
    private:
    double real;
    double imag;
    public:
    complex(double r=0.0, double i=0.0) : real(r), imag(i) {}
    complex operator+(const complex& other) const {
        return complex(real + other.real, imag + other.imag);
    }
    complex operator-(const complex& other) const {
        return complex(real - other.real, imag - other.imag);
    }
    complex operator-() const {
        return complex(-real, -imag);
    }
    bool  operator==(const complex& other) const {
        return real == other.real && imag == other.imag;
    }
    complex& operator++() {
        ++real;
        return *this;
    }
    complex operator++(int) {
        complex temp = *this;
        ++real;
        return temp;
    }
    double operator[](int index) const {
        if (index == 0) return real;
         if (index == 1) return imag;
         throw out_of_range("Index out of range");
   } 
   friend ostream& operator<<(ostream& os, const complex& c) 
   {
        os << c.real ;
        if (c.imag >= 0) os << " + " << c.imag << "i";
        else os << " - " << (-c.imag )<< "i";
        return os;
    }
    friend istream& operator>>(istream& is, complex& c);
};

istream& operator>>(istream& is, complex& c) {
    cout << "Enter real part: ";
    is >> c.real;
    cout << "Enter imaginary part: ";
    is >> c.imag;
    return is;
}

int main() {
    complex c1(2.0, 3.0);
    complex c2(1.0, 4.0);   
    cout<<"c1="<<c1<<endl;
    cout<<"c2="<<c2<<endl;  
    cout<<"c1+c2="<<c1+c2<<endl;
    cout<<"c1-c2="<<c1-c2<<endl;
    cout<<"-c1="<<-c1<<endl;
    cout<<"c1==c2: "<<(c1==c2)<<endl;
    cout<<"c1[0]="<<c1[0]<<endl;
    cout<<"c1[1]="<<c1[1]<<endl;
    return 0;
}