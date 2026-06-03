#include<iostream>
#include<string>
using namespace std;
template<typename T>
T getMax(T a, T b){
    return (a>b)?a:b;
}
template<typename T,typename U>
auto add(T a, U b) -> decltype(a+b){
    return a+b;
}
int main(){
    cout<<"Max of 3 and 5: "<<getMax(3,5)<<endl;
    cout<<"Max of 3.5 and 2.1: "<<getMax(3.5,2.1)<<endl;
    cout<<"Max of 'a' and 'b': "<<getMax('a','b')<<endl;
    cout<<"max (explicite double): "<<getMax<double>(3,5.5)<<endl;
    cout<<"add int and double: "<<add(3,5.5)<<endl;
    cout<<"add int and string: "<<add(to_string(3),to_string(100))<<endl;
    return 0;
}