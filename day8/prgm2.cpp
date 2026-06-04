#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream file("nonexistent.txt");
    if(!file)
    {
        cout<<"file not found."<<endl;
    }
    if(file.fail())
    {
        cout<<"failed to open the file."<<endl;
    }
    if(file.is_open()){
        cout<<"file opened successfully."<<endl;
        file.close();
    }
    ifstream file2("example.txt");
    if(file2.good())
    {
        cout<<"file is good for reading."<<endl;
    }
    file2.close();
    return 0;
}