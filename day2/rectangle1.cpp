#include "rectangle.h"
#include <iostream.h>
using namespace std;
rectangle::rectangle(){
          length=0;
          width=0;

}
rectangle::rectangle(double l, double w){
          length=l;
          width=w;

}
void rectangle::setDimensions(double l, double w){
          length=l;
          width=w;

} 
double rectangle::area(){
          return length*width;

}
double rectangle::perimeter(){
          return 2*(length+width);

}
void rectangle::display(){
          cout<<"Length: "<<length<<endl;
          cout<<"Width: "<<width<<endl;
          cout<<"Area: "<<area()<<endl;
          cout<<"Perimeter: "<<perimeter()<<endl;} 






include "rectangle.h"
 int main(){
    rectangle r1;
    rectangle r2(5.0,3.0);
    r1.display();
    r2.display();
    r1.setdimensions(4.5,2.5);
    r1.display();
    return 0;
}