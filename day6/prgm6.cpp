#include<iostream>
#include<string>
#include<vector>
using namespace std;
class payment{
    protected:
    double amount;
    string transactionId;
    public:
    payment(double amt, string Id) : amount(amt), transactionId(Id) {}
    virtual void process()=0;
    virtual string getType() const =0;
    virtual ~payment() {}
};
class creditCardPayment:public payment{
    private:
    string cardNumber;
    public:
    creditCardPayment(double amt, string Id, string cardNo) : payment(amt, Id), cardNumber(cardNo) {}
    void process() override {
        cout<<"Processing credit card payment of "<<amount<<endl;
        cout<<"Transaction ID: "<<transactionId<<endl;
        cout<<"Card Number: "<<cardNumber.substr(cardNumber.length()-4)<< " -approved"<<endl;
    }
    string getType() const override {
        return "Credit Card";
    }
};
class paypalPayment:public payment{
    private:
    string email;
    public:
    paypalPayment(double amt, string Id, string email) : payment(amt, Id), email(email) {}
    void process() override {
        cout<<"Processing PayPal payment of "<<amount<<endl;
        cout<<"Transaction ID: "<<transactionId<<endl;
        cout<<"PayPal Email: "<<email<<" -approved"<<endl;
    }
    string getType() const override {
        return "PayPal";
    }
};
class cryptopayment:public payment{
    private:
    string walletAddress;
    public:
    cryptopayment(double amt, string Id, string wallet) 
    : payment(amt, Id), walletAddress(wallet) {}
    void process() override {
        cout<<"Processing cryptocurrency payment of "<<amount<<endl;
        cout<<"Transaction ID: "<<transactionId<<endl;
        cout<<"Wallet Address: "<<walletAddress.substr(walletAddress.length()-6)<< " -approved"<<endl;
    }
    string getType() const override {
        return "Cryptocurrency";
    }
};
int main(){
    vector<payment*> payments;
    payments.push_back(new creditCardPayment(100.0, "TXN12345", "1234-5678-9012-3456"));
    payments.push_back(new paypalPayment(50.0, "TXN67890", "user@example.com"));
    payments.push_back(new cryptopayment(25.0, "TXN11223", "0x1234567890abcdef"));

    for (const auto& payment : payments) {
        payment->process();
        cout << "Payment Type: " << payment->getType() << endl;
        cout << "------------------------" << endl;
    }

    // Clean up memory
    for (auto& payment : payments) {
        delete payment;
    }

    return 0;
}