#include<iostream>
#include<string>
using namespace std;
class animal{
    virtual void speak(){
        cout<<"animal makes a sound"<<endl;
    }
    void eat(){
        cout<<"animal eats food"<<endl;
    }
    virtual ~animal(){}
};
class dog:public animal{
    public:
    void speak()override{
        cout<<"dog barks"<<endl;
    }
    void eat(){
        cout<<"dog eats bones"<<endl;
    }
};
class cat:public animal{
    public:
    void speak()override{
        cout<<"cat meows"<<endl;
    }
    void eat(){
        cout<<"cat eats fish"<<endl;
    }
};
int main(){
animal*animals[3];
animals[0]=new animal();
animals[1]=new dog();   
animals[2]=new cat();
cout<<"virtual function calls:"<<endl;
for(int i=0;i<3;i++){
    animals[i]->speak();  
}       
cout<<"\nnon-virtual function calls:"<<endl;
for(int i=0;i<3;i++){
    animals[i]->eat();    
}       
for(int i=0;i<3;i++){
    delete animals[i];    
}
return 0;
} 