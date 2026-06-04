#ifndef BOOK_H
#define BOOK_H
#include<string>
#include<iosteram>
using namespace std;
class book{
    private:
    int id;
    string title;
    string author;
    int year;
    bool isissued;
    public:
    book();
    book(int id,string title,sting author,int year);
    int getid()const;
    string gettitle()const;
    string getauthor()const;
    int getyear()const;
    bool getisissued()const;
    void settitle(const string& title);
    void setauthor(const string& author);
    void setyear(int year);
    void issue()
    void returnbook();
    void display()const;
    string tofilestring()const;
    static book fromfilestring(const string& line);
};
#endif
