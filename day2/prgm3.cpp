#include<iostream.h>
using namespace std;
class demo{
    public:
    int id;
    demo(int i){
        id=i;
        cout<<"Constructor called for id: "<<id<<endl;
    }
    ~demo(){
        cout<<"Destructor called for id: "<<id<<endl;
    }
};
int main(){
    cout<<"stack ibject"<<endl;
    demo stackObj(1);
    cout<<"heap object"<<endl;
    demo* heapObj=new demo(2);
    cout<<"\n stack object going out of scope automatically"<<endl;
    cout<<"heap object must be explicitly deleted"<<endl;
    delete heapObj;
    cout<<"End of main function"<<endl;
    return 0;   
}
    