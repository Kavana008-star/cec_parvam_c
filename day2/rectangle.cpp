#ifndef Rectangle_H
#define Rectangle_H

class Rectangle {
    private:
    double length;
    double width;

    public:
    Rectangle();
    Rectangle(double l, double w);
    void setDimensions(double l, double w);
    double area();
    double perimeter();
    void display();
};
#endif






include "rectangle.h"
 int main(){
    rectangle r1;
    reactangle r2(5.0,3.0);
    r1.display();
    r2.display();
    r1.setdimensions(4.5,2.5)
    r1.display()
    return 0;
}