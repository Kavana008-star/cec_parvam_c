#include<iostream>
using namespace std;
class BankAccount
{
    private:
    string accountHolder;
    double balance;
    public:
    BankAccount(string accNo, double bal) : accountHolder(accNo), balance(bal) {}
friend void displyAccountInfo( const BankAccount& acc); 
friend class auditor;
};
void displyAccountInfo( const BankAccount& acc)
{
    cout<<"Account Holder: "<<acc.accountHolder<<endl;
    cout<<"Balance: "<<acc.balance<<endl;
}
class auditor
{
    public:
    void audit(const BankAccount& acc)
    {
        cout<<"Audit report "<<endl;
        cout<<"Auditing Balance: "<<acc.accountHolder<<endl;
        cout<<"Audit complete for "<<acc.balance<<endl;
    }
};
int main()
{
    BankAccount acc1("John Doe", 1000.50);
    displyAccountInfo(acc1);
    auditor aud;
    aud.audit(acc1);
    return 0;
}