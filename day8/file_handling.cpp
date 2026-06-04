#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    ofstream outfile("example.txt");
    if(outfile.is_open())
    {
        outfile<<"hello,file!"<<endl;
        outfile<<"this is line 2."<<endl;
        outfile<<"c++ is an example of file handling."<<endl;
        outfile.close();    
        cout<<"file written successfully."<<endl;
    }
    else
    {
        cout<<"error:could not open the file."<<endl;
    }
    ifstream infile("example.txt");
    if(infile.is_open())
    {
        string line;
        while(getline(infile,line))
        {
            cout<<line<<endl;
        }
        infile.close();
    }
    else
    {
        cout<<"error:could not open the file."<<endl;
    }
    return 0;
}