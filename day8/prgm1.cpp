#include<fstream>
using namespace std;
ios::in
ios::out
ios::app    
ios::ate
ios::trunc
ios::binary
ifstream file1("data.txt");
ofstream file2("output.txt");
fstream file3("data.txt",ios::app);
fstream file4("data.txt",ios::in|ios::out);
ofstream file5("data.bin",ios::out|ios::binary);