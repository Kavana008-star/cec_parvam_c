#include<iostream>
#include<string> 
using namespace std;
class resource  
{
    private:
    int*data;
    int id;
    public:
    resource(int i,int val):id(i)
    {
        data=new int(val);
        cout<<"resource"<<"acquired (value: "<<*data<<", id: "<<id<<")"<<endl;
    }
    ~resource()
    {
        cout<<"destructor called for "<<id<<endl;
        delete data;
        cout<<"resource"<<id<<" released"<<endl; 

    }
    void show()
    {
        cout<<"resource id: "<<id<<"; "<<*data<<endl;
    }
};
void function()
{
    resource local(2,200);
    local.show();
}
int main()
{
    resource* r3=new resource(3,300);
    r3->show();
    function();
    delete r3;
    cout<<"\n end of main()"<<endl;
    return 0;
} 