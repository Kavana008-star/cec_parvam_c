#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ofstream outFile("students.txt");
    if(outFile.is_open())
    {
        outFile<<left<<setw(20)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"CGPA"<<endl;
        outFile<<string(60,'-')<<endl;
        outFile<<setw(10)<<123<<setw(20)<<"Alice"<<setw(20)<<fixed<<setprecision(2)<<3.75<<endl;
    
    outFile.close();
    }
  ifstream inFile("students.txt");
string line;
if(inFile.is_open())
{
    cout<<"=====students records======"<<endl;
    while(getline(inFile,line))
    {
        cout<<line<<endl;
    }
    inFile.close();
}
ifstream numFile("numbers.txt");
int sum=0,num;
ofstream createnum("numbers.txt");
createnum.close();
numFile.open("numbers.txt");
while(numFile>>num)
{
    sum+=num;
}
numFile.close();
cout<<"sum of numbers in file: "<<sum<<endl;
return 0;
}